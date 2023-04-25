/*
** EPITECH PROJECT, 2023
** npc_event_next_dialogue.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include "npc/npc.h"
#include <map/map.h>
#include <notifications.h>

void npc_event_next_dialogue(sprite *sprite_data, npc_s *npc_datas)
{
    survivor_s *survivor_datas = sprite_data->datas;

    npc_config_dialogue_s *temp_dialogue =
        npc_datas->config->dialogue[npc_datas->config->status];
    if (temp_dialogue->dialogue_step < temp_dialogue->nbr_dialogue_step) {
        new_notification(sprite_data->host,
            temp_dialogue->anwser[temp_dialogue->dialogue_step++], 10);
        return;
    }
    temp_dialogue->dialogue_step = 0;
    ((survivor_s *)sprite_data->datas)->freeze = false;
    if (npc_datas->config->status == 1 && !survivor_datas->special_medic_fine)
        return;
    if ((int)npc_datas->config->status < npc_datas->config->nbr_dialogue - 1)
        npc_datas->config->status++;
}
