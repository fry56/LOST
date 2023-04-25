/*
** EPITECH PROJECT, 2023
** inventory_hud_move.c
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

void inventory_hud_move(sprite *sprite_datas, sfVector2f pos)
{
    inventory_hud_s *inv_hud = sprite_datas->datas;
    inventory_hud_item_s *temp;

    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (inventory_items_config[i].name == NULL)
            return;
        temp = &inv_hud->items[i];
        if (temp->button != NULL)
            sprite_move(temp->button, pos);
        sprite_move(temp->item, pos);
        text_move(temp->amount, pos);
    }
}
