/*
** EPITECH PROJECT, 2023
** skill_tree_button.c
** File description:
** desc
*/

#include <functions.h>
#include <Class/t_window.h>
#include <Class/t_scene.h>
#include <Class/t_text.h>
#include <survivor/survivor.h>
#include <t_string.h>
#include <stdlib.h>
#include <skill_tree/skill_tree.h>
#include <t_mem.h>

static void button_skill_tree_hover(sprite *data, sfClock *clock UNUSED)
{
    animator *animator_data = data->animator;

    if (!sprite_is_mouse_over(data, &data->host->host->event))
        return;
    animator_play_animation(animator_data, "skill_tree_hover");
}

static void init_button_anim(sprite *sprite_datas, animation *anim_default,
    animation *anim_hover, animation *anim_click)
{
    new_animator(sprite_datas);
    animator_add_animation(sprite_datas->animator, anim_default);
    animator_add_animation(sprite_datas->animator, anim_hover);
    animator_add_animation(sprite_datas->animator, anim_click);
    animator_play_animation(sprite_datas->animator, "skill_tree_default");
    sprite_add_clock_update_function(sprite_datas, button_skill_tree_hover);
}

static void button_heal_click(sprite *sprite_datas, window *window_datas)
{
    animator *animator_data = sprite_datas->animator;
    survivor_s *survivor_datas = thashmap_get(sprite_datas->host->host->
        map_datas, "SURVIVOR_DATAS")->value;
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event))
        return;
    animator_play_animation(animator_data, "skill_tree_click");
    if (survivor_datas->health_level >= 3 || survivor_datas->xp < 15)
        return;
    survivor_datas->health_level++;
    survivor_datas->xp -= 10;
    skill_tree_update(sprite_datas->host);
}

static void button_speed_click(sprite *sprite_datas, window *window_datas)
{
    animator *animator_data = sprite_datas->animator;
    survivor_s *survivor_datas = thashmap_get(sprite_datas->host->host
        ->map_datas, "SURVIVOR_DATAS")->value;

    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    if (!sprite_is_mouse_click(sprite_datas, &window_datas->event))
        return;
    animator_play_animation(animator_data, "skill_tree_click");
    if (survivor_datas->speed_level >= 3 || survivor_datas->xp < 15)
        return;
    survivor_datas->speed_level++;
    survivor_datas->xp -= 10;
    skill_tree_update(sprite_datas->host);
}

void init_button_skill_tree(scene *scene_datas)
{
    animation *anim_default = thashmap_get(scene_datas->map_datas,
        "skill_tree_default")->value;
    animation *anim_hover = thashmap_get(scene_datas->map_datas,
        "skill_tree_hover")->value;
    animation *anim_click = thashmap_get(scene_datas->map_datas,
        "skill_tree_click")->value;
    sprite *heal =
        new_sprite(scene_datas, "assets/sprites/skill_tree/ok_button.png", 20);
    sprite *speed =
        new_sprite(scene_datas, "assets/sprites/skill_tree/ok_button.png", 2);

    sprite_set_pos(heal, (sfVector2f){500, 625});
    init_button_anim(heal, anim_default, anim_hover, anim_click);
    sprite_set_pos(speed, (sfVector2f){500, 825});
    new_animator(speed);
    init_button_anim(speed, anim_default, anim_hover, anim_click);
    sprite_add_event_update_function(heal, button_heal_click);
    sprite_add_event_update_function(speed, button_speed_click);
}
