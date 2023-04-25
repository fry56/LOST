/*
** EPITECH PROJECT, 2023
** map_entity_load.c
** File description:
** desc
*/

#include <map/map.h>
#include <t_xml_token.h>
#include <Class/t_sprite.h>
#include <utils.h>
#include <t_string.h>
#include <survivor/survivor.h>
#include <zombie/zombie.h>
#include <inventory/inventory_items_config.h>

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
        new_item_object(temp->host, temp_pos, temp_angle, tstr_cpy(NULL,
            t_xml_get_node_by_tag(object, "item_name")->inner_text));
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
    if (tstr_cmp(temp->name, "river_map") == 0)
        new_special_medkit_object(temp->host, (sfVector2f){3712, 2368});
}

void map_entity_load( map_s *temp, t_xml_node *map_node)
{
    load_zombie(temp, t_xml_get_node_by_tag(map_node, "zombies_list"));
    load_object(temp, t_xml_get_node_by_tag(map_node, "objects_list"));
}
