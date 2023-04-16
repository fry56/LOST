/*
** EPITECH PROJECT, 2023
** destroy.c
** File description:
** desc
*/

#include <Class/t_scene.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <stdlib.h>

static void clear_object(scene *temp)
{
    list_foreach(temp->list_sprites, node)
        sprite_destroy(node->value);
    tlist_clear(temp->list_sprites);
    list_foreach(temp->list_texts, node)
        text_destroy(node->value);
    tlist_clear(temp->list_texts);
    tlist_free(temp->list_keys);
    tlist_clear(temp->list_event_update_functions);
    free(temp->list_event_update_functions);
    tlist_clear(temp->list_clock_update_functions);
    free(temp->list_clock_update_functions);
}

void scene_destroy(scene *scene_datas)
{
    if (scene_datas->host->actual_scene->value == scene_datas)
        return;
    clear_object(scene_datas);
}
