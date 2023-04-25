/*
** EPITECH PROJECT, 2023
** inventory_add_btn_anim.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_text.h>
#include <inventory/inventory.h>

static void button_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "inventory_btn_hover");
}

void inventory_add_btn_anim(scene *scene_datas, sprite *sprite_datas)
{
    animation *btn_default =
        thashmap_get(scene_datas->map_datas, "inventory_btn_default")->value;
    animation *btn_hover =
        thashmap_get(scene_datas->map_datas, "inventory_btn_hover")->value;
    animation *btn_click =
        thashmap_get(scene_datas->map_datas, "inventory_btn_click")->value;

    new_animator(sprite_datas);
    animator_add_animation(sprite_datas->animator, btn_default);
    animator_add_animation(sprite_datas->animator, btn_hover);
    animator_add_animation(sprite_datas->animator, btn_click);
    sprite_set_fixed_origin(sprite_datas, (sfVector2f){35, 70});
    sprite_add_clock_update_function(sprite_datas, button_hover);
}
