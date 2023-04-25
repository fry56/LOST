/*
** EPITECH PROJECT, 2023
** inventory_hud_init.c
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

static void new_item(sprite *background, sfVector2f pos, int index)
{
    inventory_hud_s *inv_hud = background->datas;
    inventory_hud_item_s *temp_item = &inv_hud->items[index];

    temp_item->button = NULL;
    temp_item->item = new_sprite(background->host,
        inventory_items_config[index].path, 101);
    sprite_set_pos(temp_item->item, (sfVector2f){
        pos.x + (inv_hud->index_item * 85) + 65, pos.y + 100});
    temp_item->amount = new_text(background->host, "0/0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    text_set_pos(temp_item->amount, (sfVector2f){
            pos.x + (inv_hud->index_item * 90) + 40, pos.y + 125});
    inv_hud->index_item++;
}

static void new_object(sprite *background, sfVector2f pos, int index)
{
    inventory_hud_s *inv_hud = background->datas;
    inventory_hud_item_s *temp_item = &inv_hud->items[index];

    temp_item->item = new_sprite(background->host,
        inventory_items_config[index].path, 102);
    sprite_set_pos(temp_item->item, (sfVector2f){
        pos.x + (inv_hud->index_object * 25) + 65, pos.y + 250});
    temp_item->amount = new_text(background->host, "0/0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    text_set_pos(temp_item->amount, (sfVector2f){
        pos.x + (inv_hud->index_object * 15) + 40, pos.y + 275});
    temp_item->button = new_sprite(background->host,
        "assets/sprites/inventory/inventory_button.png", 101);
    sprite_set_pos(temp_item->button, (sfVector2f){
            pos.x + (inv_hud->index_object * 25) + 65, pos.y + 318});
    temp_item->button->datas = &inventory_items_config[index];
    sfSprite_setScale(temp_item->button->sf_sprite, (sfVector2f){1, 1.5f});
    inventory_add_btn_anim(background->host, temp_item->button);
    sprite_add_event_update_function(temp_item->button, inventory_hud_click);
    inv_hud->index_object++;
}

static void init_item(sfVector2f pos,
    sprite *background)
{
    for (int i = 0; i < NBR_ITEMS; ++i) {
        if (inventory_items_config[i].name == NULL)
            return;
        if (inventory_items_config[i].type == item)
            new_item(background, pos, i);
        else
            new_object(background, pos, i);
    }
}

void init_button_anim(scene *scene_datas)
{
    animation *btn_default =
        new_animation("inventory_btn_default", NULL, true, 10);
    animation *btn_hover =
        new_animation("inventory_btn_hover", NULL, false, 10);
    animation *btn_click =
        new_animation("inventory_btn_click", NULL, false, 10);

    thashmap_add(scene_datas->map_datas, "inventory_btn_default", btn_default);
    thashmap_add(scene_datas->map_datas, "inventory_btn_hover", btn_hover);
    thashmap_add(scene_datas->map_datas, "inventory_btn_click", btn_click);
    animation_add_frame(btn_default, (sfIntRect){0, 0, 70, 70});
    animation_add_frame(btn_hover, (sfIntRect){0, 70, 70, 70});
    animation_add_frame(btn_click, (sfIntRect){0, 114, 70, 70});
}

sprite *inventory_hud_init(scene *scene_datas, sfVector2f pos)
{
    sprite *background =
        new_sprite(scene_datas, "assets/sprites/inventory/inventory.png", 100);
    inventory_hud_s *inv_hud = tcalloc(1, sizeof(inventory_hud_s));

    background->datas = inv_hud;
    sprite_add_flag(background, "inventory_hud");
    sprite_add_flag(background, "canva");
    pos = (sfVector2f){pos.x + 200, pos.y - 200};
    sprite_set_pos(background, pos);
    sfSprite_setScale(background->sf_sprite, (sfVector2f){0.5f, 1});
    sprite_set_fixed_origin(background, (sfVector2f){0, 0});
    init_button_anim(scene_datas);
    init_item(pos, background);
    background->move = inventory_hud_move;
    inventory_hud_toggle(scene_datas);
    return background;
}
