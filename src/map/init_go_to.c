/*
** EPITECH PROJECT, 2023
** init_go_to.c
** File description:
** desc
*/

#include <map/map.h>
#include <utils.h>
#include <t_string.h>

void go_to(sprite *sprite_datas, box_collider_s *collider)
{
    sprite *new_sprite_datas;

    if (!sprite_have_flag(sprite_datas, "survivor"))
        return;
    window_change_scene(sprite_datas->host->host, collider->datas);
    new_sprite_datas = sprite_get_by_flag(
        sprite_datas->host->host->actual_scene->value, "survivor");
    if (new_sprite_datas != NULL)
        survivor_update_map(new_sprite_datas);
}

void init_go_to(map_s *temp, t_xml_node *go_to_node)
{
    t_xml_node *temp_got_to;
    box_collider_s *temp_collider;
    sfVector2f temp_pos;

    if (go_to_node == NULL)
        return;
    list_foreach(go_to_node->list_children, node) {
        temp_got_to = node->value;
        temp_pos = get_xml_pos(temp_got_to, "pos");
        temp_collider = new_box_collider(temp->box_colliders_mgr,
            (sfIntRect){temp_pos.x, temp_pos.y, 50, 50}, false);
        temp_collider->datas = tstr_cpy(NULL,
            t_xml_get_node_by_tag(temp_got_to, "map_name")->inner_text);
        temp_collider->on_enter = go_to;
    }
}
