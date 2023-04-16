/*
** EPITECH PROJECT, 2022
** map_new.c
** File description:
** desc
*/

#include <t_list.h>
#include <t_mem.h>
#include <t_assert.h>

t_list *tlist_new(void)
{
    t_list *new_list = tcalloc(1, sizeof(t_list));

    tassert(new_list == NULL && "new_list == NULL");
    return new_list;
}
