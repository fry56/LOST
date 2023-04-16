/*
** EPITECH PROJECT, 2022
** t_list.h
** File description:
** desc
*/
#ifndef t_list_h
    #define t_list_h

    #include "t_ctype.h"

    typedef struct list_node {
        struct list *host;
        void *value;
        struct list_node *next;
        struct list_node *prev;
    } t_list_node;

    typedef struct list {
        t_list_node *head;
        t_list_node *tail;
        tsize_t length;
    } t_list;

    #define list_foreach(list, node) \
            for (t_list_node *node = list->head; node; node = node->next)

    #define list_foreach_rev(list, node) \
            for (t_list_node *node = list->tail; node; node = node->prev)

    t_list *tlist_new(void);
    t_list_node *tlist_get(t_list *list, tsize_t index);
    t_list_node *tlist_add(t_list *list, void *value);
    bool tlist_remove(t_list *list, t_list_node *node);
    void *tlist_pop(t_list *list);
    t_list_node *tlist_add_before(t_list *list, t_list_node *after
        , void *value);
    t_list_node *tlist_find(t_list *list, void *value);
    void tlist_free(t_list *list);
    void tlist_clear(t_list *list);
    t_list_node *tlist_add_top(t_list *list, void *value);
    void tlist_print(t_list *list);
#endif //t_list
