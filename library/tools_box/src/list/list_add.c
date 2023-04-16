/*
** EPITECH PROJECT, 2022
** add.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_list.h>
#include <t_mem.h>
#include <t_assert.h>

void list_add_node(t_list *list, t_list_node *node)
{
    if (list == NULL || node == NULL)
        return;
    node->host = list;
    list->length++;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }
    node->next = NULL;
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
}

void list_add_node_before(t_list *list, t_list_node *after, t_list_node *node)
{
    if (list == NULL || node == NULL)
        return;
    node->host = list;
    list->length++;
    if (after->prev == NULL)
        list->head = node;
    else {
        node->prev = after->prev;
        after->prev->next = node;
    }
    after->prev = node;
    node->next = after;
}

t_list_node *tlist_add(t_list *list, void *value)
{
    t_list_node *node;

    if (list == NULL)
        return NULL;
    t_assert((node = tcalloc(1, sizeof(t_list_node))) == NULL);
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    list_add_node(list, node);
    return node;
}

t_list_node *tlist_add_before(t_list *list, t_list_node *after, void *value)
{
    t_list_node *node;

    if (list == NULL)
        return NULL;
    t_assert((node = tcalloc(1, sizeof(t_list_node))) == NULL);
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    if (after == NULL)
        list_add_node(list, node);
    else
        list_add_node_before(list, after, node);
    return node;
}

t_list_node *tlist_add_top(t_list *list, void *value)
{
    t_list_node *node;
    t_list_node *after;

    if (list == NULL)
        return NULL;
    t_assert((node = tcalloc(1, sizeof(t_list_node))) == NULL);
    if (list->head == NULL)
        return tlist_add(list, value);
    after = list->head;
    list->head->prev = node;
    list->head = node;
    node->host = list;
    node->value = value;
    node->next = after;
    node->prev = NULL;
    after->prev = node;
    list->length++;
    return node;
}
