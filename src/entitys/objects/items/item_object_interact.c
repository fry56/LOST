/*
** EPITECH PROJECT, 2023
** item_object_interact.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <interaction.h>
#include <notifications.h>
#include <inventory/inventory.h>
#include <t_string.h>
#include <stdlib.h>

void item_object_interact(sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    item_object_s *item_object = interaction_datas->datas;
    char *temp;

    if (!inventory_add_item(survivor_datas, item_object->name, 1))
        return;
    temp = tstr_compos("+1 %s", item_object->name);
    sprite_destroy(interaction_datas->host);
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_grab");
    new_notification(sprite_datas->host, temp, 10);
    free(temp);
}
