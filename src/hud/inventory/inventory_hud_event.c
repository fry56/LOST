/*
** EPITECH PROJECT, 2023
** inventory_hud_event.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <survivor/survivor.h>
#include <inventory/inventory.h>
#include <craft/craft.h>

void inventory_hud_event_toggle(sprite *sprite_datas, window *window_datas)
{
    if (window_datas->event.type != sfEvtKeyPressed ||
        window_datas->event.key.code != sfKeyE)
        return;
    inventory_hud_toggle(sprite_datas->host);
}

void inventory_hud_click(sprite *sprite_datas, window *window_datas)
{
    inventory_item_config_s *item = sprite_datas->datas;
    sprite *survivor_sprite;

    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event))
        return;
    survivor_sprite = sprite_get_by_flag(sprite_datas->host, "survivor");
    if (window_datas->event.mouseButton.button == sfMouseRight)
        craft_new_object(survivor_sprite, item->name);
    if (window_datas->event.mouseButton.button == sfMouseLeft)
        inventory_use_item(survivor_sprite->datas, item->name);
    inventory_hud_update(sprite_get_by_flag(
        sprite_datas->host, "inventory_hud"));
}
