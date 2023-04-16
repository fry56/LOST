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
#include <survivor/weapon/weapon_config.h>
#include <inventory/inventory_items_config.h>
#include <t_printf.h>

static void load_zombie(map_s *temp, t_xml_node *map_node)
{
    list_foreach(map_node->list_children, node)
        zombie_init(temp->host,
            get_xml_pos(((t_xml_node *)node->value), "pos"));
};

static void exec_function_by_type_object(map_s *temp, t_xml_node *object,
    sfVector2f temp_pos, float temp_angle)
{
    int temp_type = tstr_to_number(
        t_xml_get_node_by_tag(object, "type")->inner_text);

    if (temp_type == 0)
        new_item_object(temp->host, temp_pos, temp_angle,
            t_xml_get_node_by_tag(object, "item_name")->inner_text);
    if (temp_type == 1)
        new_weapon_object(temp->host, temp_pos, temp_angle,
            tstr_to_number(t_xml_get_node_by_tag(object,
                "weapon_type")->inner_text));
    if (temp_type == 2)
        new_ammos_object(temp->host, temp_pos, temp_angle,
            tstr_to_number(t_xml_get_node_by_tag(object,
                "weapon_type")->inner_text));
}

static void load_object(map_s *temp, t_xml_node *map_node)
{
    t_xml_node *object;
    float temp_angle;
    sfVector2f temp_pos;

    list_foreach(map_node->list_children, node) {
        object = node->value;
        temp_angle = (float)tstr_to_number(
            t_xml_get_node_by_tag(object, "type")->inner_text);
        temp_pos = get_xml_pos(((t_xml_node *)node->value), "pos");
        exec_function_by_type_object(temp, object, temp_pos, temp_angle);
    }
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
        ini_scene(temp->host, map_node);
        map_load_tiled(temp,
            t_xml_get_node_by_tag(map_node, "path")->inner_text);
        survivor_init(temp->host, get_xml_pos(map_node, "survivor_pos"));
        load_zombie(temp, t_xml_get_node_by_tag(map_node, "zombies_list"));
        load_object(temp, t_xml_get_node_by_tag(map_node, "objects_list"));
    }
    t_xml_free(map_conf);
}
