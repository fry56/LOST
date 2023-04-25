/*
** EPITECH PROJECT, 2023
** craft_new_object.c
** File description:
** desc
*/

#include <craft/craft_config.h>
#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <inventory/inventory_items_config.h>
#include <utils.h>
#include <t_string.h>

static bool have_any_required_item(craft_receipts_s *craft_receipts,
    inventory_mgr_s *inventory_mgr)
{
    uint16_t item = craft_receipts->nbr_required_item;

    for (int i = 0; i < NBR_ITEMS && item > 0; ++i) {
        if (inventory_items_config[i].name == NULL)
            continue;
        if (tstr_cmp(craft_receipts->items_require[item - 1].name,
            inventory_mgr->items[i].name))
            continue;
        if (inventory_mgr->items[i].amount <
            craft_receipts->items_require[item - 1].amount)
            return false;
        item--;
        i = -1;
    }
    return item == 0 ? true : false;
}

static void remove_any_required_item(craft_receipts_s *craft_receipts,
    survivor_s *survivor_datas)
{
    for (int i = 0; i < craft_receipts->nbr_required_item; ++i) {
        inventory_remove_item(survivor_datas,
            craft_receipts->items_require[i].name,
            craft_receipts->items_require[i].amount);
    }
}

static bool have_required_space(craft_receipts_s *craft_receipts,
    inventory_mgr_s *inventory_mgr)
{
    inventory_item_config_s *config =
        get_item_by_name(craft_receipts->new_object_name);

    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (tstr_cmp(inventory_mgr->items[i].name,
            craft_receipts->new_object_name))
            continue;
        return config->max_amount > inventory_mgr->items[i].amount;
    }
    return false;
}

bool craft_new_object(sprite *sprite_datas, char *new_object_name)
{
    survivor_s *survivor_datas = sprite_datas->datas;
    inventory_mgr_s *inventory_mgr = survivor_datas->inventory_mgr;
    craft_receipts_s *craft_receipts = get_craft_by_name(new_object_name);

    if (craft_receipts == NULL)
        return false;
    if (!have_required_space(craft_receipts, inventory_mgr))
        return false;
    if (!have_any_required_item(craft_receipts, inventory_mgr))
        return false;
    remove_any_required_item(craft_receipts, survivor_datas);
    inventory_add_item(survivor_datas, craft_receipts->new_object_name,
        craft_receipts->amount);
    return true;
}
