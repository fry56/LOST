/*
** EPITECH PROJECT, 2023
** get_craft_by_name.c
** File description:
** desc
*/

#include "t_string.h"
#include <craft/craft_config.h>

craft_receipts_s *get_craft_by_name(char *name)
{
    for (int i = 0; craft_receipts_config[i].new_object_name != NULL; ++i) {
        if (tstr_cmp(craft_receipts_config[i].new_object_name, name) == 0)
            return &craft_receipts_config[i];
    }
    return NULL;
}
