/*
** EPITECH PROJECT, 2023
** init_skill_tree.c
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

static void return_to_pause(scene *scene_datas UNUSED, window *window_datas)
{
    t_hashmap_node *scene = thashmap_get(window_datas->map_datas,
        "prev_scene");
    if (window_datas->event.type != sfEvtKeyPressed ||
        window_datas->event.key.code != sfKeyEscape)
        return;
    window_change_scene(window_datas, "pause_menu");
    scene->value = "pause_menu";
}

static void init_skill_tree_button(scene *scene_datas)
{
    animation *skill_tree_default;
    animation *skill_tree_hover;
    animation *skill_tree_click;

    skill_tree_default = new_animation("skill_tree_default", NULL, true, 10);
    animation_add_frame(skill_tree_default, (sfIntRect){0, 0, 61, 56});
    thashmap_add(scene_datas->map_datas,
        "skill_tree_default", skill_tree_default);
    skill_tree_hover = new_animation("skill_tree_hover", NULL, false, 10);
    animation_add_frame(skill_tree_hover, (sfIntRect){0, 56, 61, 56});
    thashmap_add(scene_datas->map_datas,
        "skill_tree_hover", skill_tree_hover);
    skill_tree_click = new_animation("skill_tree_click", NULL, false, 10);
    animation_add_frame(skill_tree_click, (sfIntRect){0, 112, 61, 56});
    thashmap_add(scene_datas->map_datas,
        "skill_tree_click", skill_tree_hover);
    init_button_skill_tree(scene_datas);
}

void init_skill_tree(scene *scene_datas)
{
    sprite *background = new_sprite(scene_datas,
        "assets/sprites/skill_tree/skills.png", 0);
    skill_tree_s *skill_tree_data = tcalloc(1, sizeof(skill_tree_s));

    scene_datas->datas = skill_tree_data;
    sfSprite_setOrigin(background->sf_sprite, (sfVector2f){0, 0});
    skill_tree_data->xp = new_text(scene_datas, "0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    text_set_pos(skill_tree_data->xp, (sfVector2f){150, 300});
    text_set_font_size(skill_tree_data->xp, 32);
    skill_tree_data->heal = new_text(scene_datas, "0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    text_set_pos(skill_tree_data->heal, (sfVector2f){300, 510});
    skill_tree_data->speed = new_text(scene_datas, "0",
        "assets/font/inter.woff2", (rgb){255, 255, 255});
    text_set_pos(skill_tree_data->speed, (sfVector2f){270, 710});
    scene_add_event_update_function(scene_datas, return_to_pause);
    init_skill_tree_button(scene_datas);
}
