/*
** EPITECH PROJECT, 2023
** map_load.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <paths.h>
#include <t_mem.h>
#include <t_assert.h>
#include <utils.h>
#include <t_string.h>
#include <survivor/survivor.h>
#include <zombie/zombie.h>
#include <inventory/inventory_items_config.h>
#include <npc/npc.h>

static void init_survivor_datas(scene *scene_datas, t_xml_node *map_node)
{
    sprite *new_sprite_datas;
    sfVector2f pos = get_xml_pos(map_node, "survivor_pos");

    inventory_hud_init(scene_datas, pos);
    weapon_hud_init(scene_datas, pos);
    survivor_init(scene_datas, pos);
    if (!tstr_to_number(t_xml_get_node_by_tag(map_node, "default")->inner_text))
        return;
    new_sprite_datas = sprite_get_by_flag(scene_datas, "survivor");
    survivor_update_map(new_sprite_datas);
}

void map_load(window *window_datas)
{
    t_xml *map_conf = t_xml_load(maps_config_path);
    map_s *temp;
    t_xml_node *map_node;
    list_foreach(map_conf->root->list_children, node) {
        map_node = node->value;
        tassert((temp = tcalloc(1, sizeof(map_s))) == NULL);
        temp->name = tstr_cpy(NULL,
            t_xml_get_node_by_tag(map_node, "name")->inner_text);
        temp->host = new_scene(window_datas, temp->name, NULL, NULL);
        temp->host->datas = temp;
        temp->list_tileset = tlist_new();
        init_scene(temp->host, map_node);
        map_load_tiled(temp,
            t_xml_get_node_by_tag(map_node, "path")->inner_text);
        map_entity_load(temp, map_node);
        init_go_to(temp, t_xml_get_node_by_tag(map_node, "go_to_list"));
        init_survivor_datas(temp->host, map_node);
        init_npc(temp, t_xml_get_node_by_tag(map_node, "npc_list"));
    }
    t_xml_free(map_conf);
}
