/*
** EPITECH PROJECT, 2023
** init_player_datas.c
** File description:
** desc
*/

#include "t_ctype.h"
#include "Class/t_window.h"
#include "survivor/survivor.h"
#include "t_mem.h"
#include "t_assert.h"


bool survivor_init_datas(window *window_datas)
{
    survivor_s *survivor_datas = tcalloc(1, sizeof(survivor_s));
    tassert(survivor_datas == NULL);
    survivor_init_inventory_mgr(survivor_datas);
    survivor_init_weapon_mgr(survivor_datas);
    thashmap_add(window_datas->map_datas, "SURVIVOR_DATAS", survivor_datas);
    return true;
}
