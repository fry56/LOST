/*
** EPITECH PROJECT, 2023
** init_collisions.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <box_collider/box_collider.h>
#include <box_collider/box_collider_config.h>
#include <t_assert.h>
#include <utils.h>
#include <t_string.h>

static void create_new_box_collider(map_s *map_datas,
    map_tileset_index_s *temp_tileset, sfVector2i pos, long id)
{
    box_collider_config_s config;

    if (id == 0)
        return;
    id = id - temp_tileset->start_index;
    config = box_colliders_configs[id];
    for (int i = 0; i < config.nbr_collisions; ++i) {
        new_box_collider(map_datas->box_colliders_mgr, (sfIntRect){
            (pos.x * temp_tileset->host->t_width) +
                config.box[i].width + config.box[i].left,
            (pos.y * temp_tileset->host->t_height) +
                config.box[i].height + config.box[i].top,
            config.box[i].width,
            config.box[i].height
        }, true);
    }
}

static void layer_collider_compose(map_s *map_datas, char *datas)
{
    long id = 0;
    size_t length = tstr_len(datas) - 1;
    sfVector2i pos = {0, 0};
    map_tileset_index_s *temp_tileset = NULL;

    for (size_t i = 1; i < length; i++) {
        if (datas[i] == '\n' && i + 1 < length) {
            pos = (sfVector2i){0, pos.y + 1};
            continue;
        }
        if (datas[i] == ',' || i + 1 == length) {
            tassert((temp_tileset = get_tileset(map_datas, id)) == NULL);
            create_new_box_collider(map_datas, temp_tileset, pos, id);
            id = 0;
            pos.x++;
            continue;
        }
        id = (id * 10) + (datas[i] - 48);
    }
}

void init_collider_layer(map_s *map_datas, t_xml_node *node)
{
    char *data = t_xml_get_node_by_tag(node, "data")->inner_text;

    init_box_coliders_manager(map_datas);
    layer_collider_compose(map_datas, data);
    init_pathfinding_manager(map_datas);
}
