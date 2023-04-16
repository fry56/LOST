/*
** EPITECH PROJECT, 2023
** weapon_add_ammos.c
** File description:
** desc
*/

#include <survivor/survivor.h>
#include <survivor/weapon/weapon_config.h>
#include <notifications.h>
#include <t_string.h>
#include <stdlib.h>

void weapon_add_ammos(sprite *sprite_datas, weapons_type_e type,
    uint16_t amount)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;
    char *temp = tstr_compos("+%d %s ammos",
        (int)amount, weapons_config[type].name);

    weapon_mgr->weapons[type].ammos += amount;
    new_notification(sprite_datas->host, temp, 5);
    free(temp);
}
