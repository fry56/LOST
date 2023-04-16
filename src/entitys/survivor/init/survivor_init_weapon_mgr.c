/*
** EPITECH PROJECT, 2023
** survivor_init_weapon_mgr.c
** File description:
** desc
*/

#include "t_ctype.h"
#include "survivor/survivor.h"
#include "t_mem.h"
#include "t_assert.h"

void survivor_init_weapon_mgr(survivor_s *survivor_datas)
{
    weapons_manager_s *weapon_mgr;

    tassert((survivor_datas->weapon_mgr =
        tcalloc(1, sizeof(weapons_manager_s))) == NULL);
    weapon_mgr = survivor_datas->weapon_mgr;
    weapon_mgr->equiped_weapon = weapon_knife;
    weapon_mgr->timestamp_weapon_change = 0;
    weapon_mgr->timestamp_wait = 0;
    weapon_mgr->weapons[weapon_knife] =
        (weapon_s){weapon_knife, -1, -1, 0, 0, true};
    weapon_mgr->weapons[weapon_handgun] =
        (weapon_s){weapon_handgun, 0, 0, 0, 0, true};
    weapon_mgr->weapons[weapon_rifle] =
        (weapon_s){weapon_rifle, 0, 0, 0, 0, false};
    weapon_mgr->weapons[weapon_shotgun] =
        (weapon_s){weapon_shotgun, 0, 0, 0, 0, false};
}
