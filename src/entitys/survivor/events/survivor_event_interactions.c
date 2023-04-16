/*
** EPITECH PROJECT, 2023
** survivor_interactions.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include "survivor/survivor.h"
#include "interaction.h"
#include "Class/t_scene.h"
#include "utils.h"

static sprite *find_nearest_iteraction(sprite *sprite_datas)
{
    float dist = 99999;
    float temp_dist;
    sprite *nearest = NULL;
    sprite *temp;

    list_foreach(sprite_datas->host->list_sprites, node) {
        temp = node->value;
        if (!sprite_have_flag(temp, "interactive"))
            continue;
        temp_dist = get_distance(temp->pos, sprite_datas->pos);
        if (temp_dist <= ((interaction_s *)temp->datas)->interaction_dist &&
            temp_dist < dist) {
            dist = temp_dist;
            nearest = temp;
        }
    }
    return nearest;
}

void survivor_event_interactions(sprite *sprite_datas, window *window_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    sprite *nearest;
    uint64_t timestamp;

    if (window_datas->event.key.code != sfKeyE ||
        window_datas->event.type != sfEvtKeyPressed)
        return;
    timestamp = sfClock_getElapsedTime(window_datas->global_clock).microseconds;
    if (timestamp < survivor_datas->timestamp_interaction + 800000 ||
        survivor_datas->freeze)
        return;
    if ((nearest = find_nearest_iteraction(sprite_datas)) == NULL)
        return;
    survivor_datas->timestamp_interaction = timestamp;
    if (((interaction_s *)nearest->datas)->onInteract != NULL)
        ((interaction_s *)nearest->datas)->
            onInteract(sprite_datas, nearest->datas);
}
