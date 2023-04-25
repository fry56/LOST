/*
** EPITECH PROJECT, 2023
** init_scene.c
** File description:
** desc
*/

#include <notifications.h>
#include <t_xml_token.h>
#include <t_string.h>
#include <survivor/survivor.h>
#include <functions.h>
#include <npc/npc.h>

static sfKeyCode binded_key[] = {
    sfKeyZ,
    sfKeyQ,
    sfKeyD,
    sfKeyS,
    sfKeyE
};

void init_scene(scene *scene_datas, t_xml_node *map_node)
{
    char *temp = t_xml_get_node_by_tag(map_node, "name")->inner_text;

    if (tstr_to_number(t_xml_get_node_by_tag(map_node,
        "default")->inner_text)) {
        thashmap_add(scene_datas->host->map_datas, "default_game_scene",
            tstr_cpy(NULL, temp));
        thashmap_add(scene_datas->host->map_datas, "current_game_scene",
            tstr_cpy(NULL, temp));
    }
    for (unsigned long i = 0; i < (sizeof(binded_key) / sizeof(sfKeyCode)); i++)
        scene_add_key_bind(scene_datas, binded_key[i]);
    notification_init(scene_datas);
    scene_add_event_update_function(scene_datas, go_pause_menu);
}
