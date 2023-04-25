/*
** EPITECH PROJECT, 2023
** inventory_hud_update.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <survivor/survivor.h>
#include <hud/weapon_hud.h>
#include <t_mem.h>
#include <inventory/inventory.h>
#include <inventory/inventory_items_config.h>
#include <survivor/survivor.h>
#include <t_string.h>
#include <stdlib.h>

void inventory_hud_update(sprite *sprite_datas)
{
    survivor_s *survivor_datas =
        sprite_get_by_flag(sprite_datas->host, "survivor")->datas;
    inventory_hud_s *hud = sprite_datas->datas;
    inventory_hud_item_s *temp;
    char *temp_string;

    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (inventory_items_config[i].name == NULL)
            return;
        temp = &hud->items[i];
        temp_string = tstr_compos("%d/%d", survivor_datas->inventory_mgr->
            items[i].amount, inventory_items_config[i].max_amount);
        text_set_content(temp->amount, temp_string);
        free(temp_string);
    }
}
