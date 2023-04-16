/*
** EPITECH PROJECT, 2023
** init_tileset_datas.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <paths.h>
#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>
#include <t_printf.h>

static void load_tileset_texture(tileset_s *tileset, char *texture_path)
{
    sfIntRect rect;
    uint32_t column = 0, ligne = 0;
    sfTexture *temp;

    tassert((tileset->images = tcalloc(tileset->tile_count,
        sizeof(sfTexture *))) == NULL);
    for (uint32_t i = 0; i < tileset->tile_count; ++i, ++column) {
        if (column > tileset->columns - 1) {
            column = 0;
            ligne++;
        }
        rect = (sfIntRect){
            column * tileset->tile_width + ((column + 1) * tileset->spacing),
            ligne * tileset->tile_height + ((ligne + 1) * tileset->spacing),
            tileset->tile_width, tileset->tile_height};
        tassert((temp = sfTexture_createFromFile(texture_path, &rect)) == NULL);
        tassert((tileset->images[i] = sfTexture_copyToImage(temp)) == NULL);
        sfTexture_destroy(temp);
    }
    free(texture_path);
}

static void get_tileset_datas(t_hashmap *tileset_map, tileset_s *tileset,
    char *path_config)
{
    char *config_temp = tstr_compos("%s/%s", maps_assets_path, path_config);
    char *texture_temp;
    t_xml *temp = t_xml_load(config_temp);
    t_xml_node *image_d = t_xml_get_node_by_tag(temp->root, "image");
    t_xml_node *tileset_d = temp->root;

    texture_temp = tstr_compos("%s/%s", maps_assets_path,
        t_xml_get_node_attribute(image_d, "source"));
    tileset->name = t_xml_get_node_attribute(tileset_d, "name");
    tileset->tile_width = t_xml_get_attribute_number(tileset_d, "tilewidth");
    tileset->tile_height = t_xml_get_attribute_number(tileset_d, "tileheight");
    if (tileset_d->list_attributes->length > 7) {
        tileset->spacing = t_xml_get_attribute_number(tileset_d, "spacing");
        tileset->margin = t_xml_get_attribute_number(tileset_d, "margin");
    }
    tileset->tile_count = t_xml_get_attribute_number(tileset_d, "tilecount");
    tileset->columns = t_xml_get_attribute_number(tileset_d, "columns");
    load_tileset_texture(tileset, texture_temp);
    tassert(thashmap_add(tileset_map, tileset->name, tileset) == NULL);
    free(config_temp);
}

static void insert_tileset_index(map_s *map_datas, tileset_s *tileset,
    t_xml_node *temp)
{
    map_tileset_index_s *tileset_index =
        tcalloc(1, sizeof(map_tileset_index_s));
    t_list_node *tileset_index_node;

    tassert(tileset_index == NULL);
    tileset_index_node = tlist_add(map_datas->list_tileset, tileset_index);
    tileset_index->tileset = tileset;
    tileset_index->start_index = t_xml_get_attribute_number(temp, "firstgid");
    tileset_index->end_index = -1;
    tileset_index->host = map_datas;
    if (map_datas->list_tileset->length > 1)
        ((map_tileset_index_s *)tileset_index_node->prev->value)->end_index =
            tileset_index->start_index - 1;
}

void map_load_tileset(map_s *map_datas, t_xml_node *root)
{
    t_hashmap *tileset_map = map_datas->host->host->datas;
    t_xml_node *temp;
    tileset_s *tileset;
    t_hashmap_node *tileset_node;
    list_foreach(root->list_children, node) {
        temp = node->value;
        if (tstr_cmp(temp->tag, "tileset") != 0)
            continue;
        if ((tileset_node = thashmap_get(tileset_map,
            t_xml_get_node_attribute(temp, "source"))) != NULL) {
            tlist_add(map_datas->list_tileset, tileset_node->value);
            insert_tileset_index(map_datas, tileset_node->value, temp);
            continue;
        }
        tassert((tileset = tcalloc(1, sizeof(tileset_s))) == NULL);
        get_tileset_datas(tileset_map, tileset, tstr_cpy(NULL,
            t_xml_get_node_attribute(temp, "source")));
        insert_tileset_index(map_datas, tileset, temp);
        tprintf("[TEXTURE] %s - Loaded\n", tileset->name);
    }
}
