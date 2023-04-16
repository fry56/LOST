/*
** EPITECH PROJECT, 2023
** zombie_init_sound_mgr.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "zombie/zombie.h"
#include "entity_animations.h"
#include "t_assert.h"

#include <zombie/zombie_sounds_config.h>

void zombie_init_sound_mgr(scene *scene_datas, sprite *new_zombie)
{
    t_hashmap_node *temp;

    for (int i = 0; zombie_sound_config[i].name != NULL ; ++i) {
        tassert((temp = thashmap_get(scene_datas->host->map_datas,
            zombie_sound_config[i].name)) == NULL);
        sound_manager_add_sound(((zombie_s *)new_zombie->datas)->sound_mgr,
            temp->value);
    }
}
