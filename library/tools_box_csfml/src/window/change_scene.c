/*
** EPITECH PROJECT, 2022
** set_scene.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>
#include <Class/t_scene.h>
#include <Class/t_sound_manager.h>

bool window_change_scene(window *self, char *scene_name)
{
    t_hashmap_node *new_scene = thashmap_get(self->map_scenes, scene_name);

    if (new_scene == NULL)
        return false;
    list_foreach(((scene *)self->actual_scene->value)->list_sound_manager, node)
        sound_manager_clear(node->value);
    self->actual_scene = new_scene;
    return true;
}
