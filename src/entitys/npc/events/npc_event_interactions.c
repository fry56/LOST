/*
** EPITECH PROJECT, 2023
** npc_event_interactions.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <interaction.h>
#include <survivor/survivor.h>
#include "npc/npc.h"
#include <map/map.h>
#include <notifications.h>

void npc_envent_interactions(sprite *sprite_datas,
    interaction_s *interaction_data)
{
    npc_s *npc_datas = interaction_data->datas;
    survivor_s *survivor_data = sprite_datas->datas;

    sfSprite_setRotation(interaction_data->host->sf_sprite,
        survivor_data->angle - 180);
    new_notification(sprite_datas->host,
        "[Appuyer sur espace pour continuer le dialogue]", 5);
    new_notification(sprite_datas->host, npc_datas->config->dialogue[
        npc_datas->config->status]->anwser[0], 10);
    survivor_data->freeze = true;
    npc_datas->config->dialogue[npc_datas->config->status]->dialogue_step++;
    survivor_data->npc_dialogue = npc_datas;
}
