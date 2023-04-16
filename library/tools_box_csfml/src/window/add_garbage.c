/*
** EPITECH PROJECT, 2023
** add_garbage.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <t_mem.h>
#include <t_assert.h>

void window_add_garbage(window *window_datas, t_list_node *node,
    void (*destroy)(void *datas))
{
    garbage *new_garbage = tcalloc(1, sizeof(garbage));

    tassert(new_garbage == NULL);
    new_garbage->node = node;
    new_garbage->destroy = destroy;
    tlist_add(window_datas->list_node_garbage, new_garbage);
}
