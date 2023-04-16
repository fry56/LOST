/*
** EPITECH PROJECT, 2023
** change_weapon.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_window.h>
#include <survivor/weapon/weapon.h>
#include <survivor/survivor.h>

static bool allow_change_weapon(survivor_s *survivor_datas,
    weapons_manager_s *weapon_mgr , window *window_datas, sfUint64 timestamp)
{
    int delta = (int)window_datas->event.mouseWheelScroll.delta;
    if (window_datas->event.type != sfEvtMouseWheelScrolled ||
        survivor_datas->freeze)
        return false;
    if (timestamp < weapon_mgr->timestamp_weapon_change + 800000)
        return false;
    if ((int)(weapon_mgr->equiped_weapon + delta) < 0 ||
        (int)(weapon_mgr->equiped_weapon + delta) > NBR_WEAPONS_TYPES - 1)
        return false;
    return true;
}

static int find_unlock_weapon(weapons_manager_s *weapon_mgr, int delta)
{
    for (int i = (int)weapon_mgr->equiped_weapon + delta;
        i < NBR_WEAPONS_TYPES && i >= 0; i += delta) {
        if (weapon_mgr->weapons[i].unlock)
            return (int) i;
    }
    return -1;
}

void weapon_change(sprite *sprite_datas, window *window_datas)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    weapons_manager_s *weapon_mgr = survivor_datas->weapon_mgr;
    int delta = (int)window_datas->event.mouseWheelScroll.delta;
    int index;
    sfUint64 timestamp =
        sfClock_getElapsedTime(window_datas->global_clock).microseconds;

    if (!allow_change_weapon(survivor_datas, weapon_mgr,
        window_datas, timestamp))
        return;
    if ((index = find_unlock_weapon(weapon_mgr, delta)) == -1)
        return;
    weapon_set(sprite_datas, index);
}
