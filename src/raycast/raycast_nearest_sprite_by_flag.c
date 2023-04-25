/*
** EPITECH PROJECT, 2023
** raycast_nearest_sprite_by_flag.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <raycast.h>
#include <utils.h>
#include <zombie/zombie.h>

sprite *raycast_nearest_sprite_by_flag(sprite *sprite_datas, float range,
    char *flag)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    sprite *touch = NULL;
    float temp_dist, dist = 9999;

    list_foreach(sprite_datas->host->list_sprites, node) {
        if (!sprite_have_flag(node->value, flag))
            continue;
        if (((zombie_s *)((sprite *)node->value))->status == death)
            continue;
        if (!raycast(sprite_datas->pos, ((sprite *)node->value)->pos,
            survivor_datas->angle + 90, 20))
            continue;
        temp_dist = get_distance(sprite_datas->pos,
            ((sprite *)node->value)->pos);
        if (temp_dist < dist && temp_dist <= range) {
            touch = node->value;
            dist = temp_dist;
        }
    }
    return touch;
}
