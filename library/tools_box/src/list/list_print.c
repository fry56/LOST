/*
** EPITECH PROJECT, 2022
** list_print.c
** File description:
** desc
*/

#include <t_list.h>
#include <t_printf.h>

void tlist_print(t_list *list)
{
    int i = 0;
    tprintf("\n\n\n");
    tprintf("--- List --- \n");
    tprintf("Pointer : %p \n", list);
    tprintf("Head : %p \n", list->head);
    tprintf("Tail : %p \n", list->tail);
    tprintf("Length : %lu \n", list->length);
    tprintf("--- Node --- \n");
    list_foreach(list, node) {
        tprintf("Node [%d] \n", i);
        tprintf("Pointer : %p \n", node);
        tprintf("Host : %p \n", node->host);
        tprintf("next : %p \n", node->next);
        tprintf("prev : %p \n", node->prev);
        tprintf("value : %p \n", node->value);
        tprintf("value(string) : %s \n", node->value);
        i++;
    }
}
