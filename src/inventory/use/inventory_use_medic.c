/*
** EPITECH PROJECT, 2023
** inventory_use_medic.c
** File description:
** desc
*/

#include <inventory/inventory.h>
#include <survivor/survivor.h>
#include <notifications.h>
#include <t_string.h>
#include <t_mem.h>

void inventory_use_medic(inventory_mgr_s *mgr, inventory_item_s *item)
{
    survivor_s *survivor_datas = mgr->host;
    int max = (100 + (survivor_datas->health_level * 25));
    char *temp;

    if (survivor_datas->health == max)
        return;
    inventory_remove_item(survivor_datas, item->name, 1);
    if (survivor_datas->health > max) {
        survivor_datas->health += max - survivor_datas->health;
        return;
    } else {
        survivor_datas->health += 50;
    }
    temp = tstr_compos("Vie : +%d\n", survivor_datas->health);
    new_notification(survivor_datas->temp_datas->host->host, temp, 10);
    free(temp);
    sound_manager_play_sound(survivor_datas->sound_mgr,
        "sound_survivor_bandage");
}
