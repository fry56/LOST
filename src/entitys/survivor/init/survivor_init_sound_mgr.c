/*
** EPITECH PROJECT, 2023
** survivor_init_sound.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "entity_animations.h"
#include "survivor/survivor_sounds_config.h"
#include "t_assert.h"

void survivor_init_sound_mgr(scene *scene_datas, sprite *new_player)
{
    t_hashmap_node *temp;

    for (int i = 0; survivor_sound_config[i].name != NULL ; ++i) {
        tassert((temp = thashmap_get(scene_datas->host->map_datas,
            survivor_sound_config[i].name)) == NULL);
        sound_manager_add_sound(((survivor_s *)new_player->datas)->sound_mgr,
            temp->value);
    }
}
