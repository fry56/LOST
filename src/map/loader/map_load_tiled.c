/*
** EPITECH PROJECT, 2023
** map_load_tiled.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>
#include <utils.h>

static void get_image_data(sfImage *temp, map_tileset_index_s *temp_tileset,
    sfVector2i pos, long id)
{
    tileset_s *tiled = temp_tileset->tileset;
    sfImage *tiled_img;
    bool horizontally, vertically, diagonally;
    horizontally = (id & FLIPPED_HORIZONTALLY_FLAG);
    vertically = (id & FLIPPED_VERTICALLY_FLAG);
    diagonally = (id & FLIPPED_DIAGONALLY_FLAG);
    id = id & ~(FLIPPED_HORIZONTALLY_FLAG | FLIPPED_VERTICALLY_FLAG |
        FLIPPED_DIAGONALLY_FLAG);
    if (id == 0 || tiled->tile_count <= id - temp_tileset->start_index)
        return;
    tiled_img = tiled->images[id - temp_tileset->start_index];
    flip_image(tiled_img, horizontally, vertically);
    if (diagonally)
        tiled_img = image_flip_diagonally(tiled_img);
    sfImage_copyImage(temp, tiled_img, pos.x * temp_tileset->host->t_width,
        pos.y * temp_tileset->host->t_height, (sfIntRect){}, false);
    flip_image(tiled->images[id - temp_tileset->start_index],
        horizontally, vertically);
    if (diagonally)
        sfImage_destroy(tiled_img);
}

static void layer_image_compose(map_s *map_datas, sfImage *temp, char *datas)
{
    long id = 0;
    sfVector2i pos = {0, 0};
    map_tileset_index_s *temp_tileset = NULL;

    for (; *datas != '\0'; datas += 1) {
        if (*datas != ',' && (*datas < '0' || *datas > '9')) {
            pos = (sfVector2i){0, pos.y + 1};
            datas++;
            continue;
        }
        if (*datas == ',') {
            tassert((temp_tileset = get_tileset(map_datas, id)) == NULL);
            get_image_data(temp, temp_tileset, pos, id);
            id = 0;
            pos.x++;
            continue;
        }
        id = (id * 10) + (*datas - 48);
    }
}

static void new_map_layer(map_s *map_datas, t_xml_node *xml_layer)
{
    sfImage *temp = sfImage_create(map_datas->width * map_datas->t_width,
        map_datas->height * map_datas->t_height);
    sfTexture *layer_texture;
    map_layer_s *layer = tcalloc(1, sizeof(map_layer_s));

    tassert(temp == NULL || layer == NULL);
    layer->id = t_xml_get_attribute_number(xml_layer, "id");
    layer->name = t_xml_get_node_attribute(xml_layer, "name");
    sfImage_createMaskFromColor(temp, sfBlack, 1);
    layer_image_compose(map_datas, temp,
        ((t_xml_node *)xml_layer->list_children->head->value)->inner_text);
    layer_texture = sfTexture_createFromImage(temp, NULL);
    layer->sprite = new_sprite(map_datas->host, NULL, layer->id);
    sfSprite_setTexture(layer->sprite->sf_sprite, layer_texture, false);
    layer->sprite->sf_texture = layer_texture;
    sprite_set_fixed_origin(layer->sprite, (sfVector2f) {0, 0});
    sprite_set_pos(layer->sprite, (sfVector2f) {0, 0});
    sfImage_destroy(temp);
    tlist_add(map_datas->list_layer, layer);
}

static void init_map_layer_factory(map_s *map_datas, t_xml_node *map_config)
{
    t_xml_node *temp;
    char *name;

    map_datas->width = t_xml_get_attribute_number(map_config, "width");
    map_datas->height = t_xml_get_attribute_number(map_config, "height");
    map_datas->t_width = t_xml_get_attribute_number(map_config, "tilewidth");
    map_datas->t_height = t_xml_get_attribute_number(map_config, "tileheight");
    list_foreach(map_config->list_children, node) {
        temp = node->value;
        if (tstr_cmp(temp->tag, "layer") != 0)
            continue;
        name = t_xml_get_node_attribute(temp, "name");
        if (tstr_cmp(name, "collider") == 0)
            init_collider_layer(map_datas, temp);
        new_map_layer(map_datas, temp);
        free(name);
    }
}

void map_load_tiled(map_s *map_datas, char *path)
{
    t_xml *map_config = t_xml_load(path);

    tassert(map_config == NULL);
    map_load_tileset(map_datas, map_config->root);
    init_map_layer_factory(map_datas, map_config->root);
}
