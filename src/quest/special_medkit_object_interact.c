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

void special_medkit_object_interact(sprite *sprite_datas,
    interaction_s *interaction_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;

    sprite_destroy(interaction_datas->host);
    sound_manager_play_sound(survivor_datas->sound_mgr, "sound_survivor_grab");
    new_notification(sprite_datas->host, "+1 special medkit", 10);
    survivor_datas->special_medic_fine = true;
}
