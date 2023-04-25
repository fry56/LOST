/*
** EPITECH PROJECT, 2023
** skill_tree_update.c
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

void skill_tree_update(scene *scene_datas)
{
    skill_tree_s *skill_tree_datas = scene_datas->datas;
    survivor_s *survivor_datas =
        thashmap_get(scene_datas->host->map_datas, "SURVIVOR_DATAS")->value;
    char *temp;

    temp = tstr_number((int)survivor_datas->xp);
    text_set_content(skill_tree_datas->xp, temp);
    free(temp);
    temp = tstr_compos("%d / 3", (int)survivor_datas->health_level);
    text_set_content(skill_tree_datas->heal, temp);
    free(temp);
    temp = tstr_compos("%d / 3", (int)survivor_datas->speed_level);
    text_set_content(skill_tree_datas->speed, temp);
    free(temp);
}
