/*
** EPITECH PROJECT, 2023
** str_match.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_string.h>

const char *split_array[] = {".*"};

char *tstr_match(char *buf, char *match)
{
    t_list *split = tstr_split_list(match, 1, split_array);
    int start_index;

    if (split == NULL)
        return NULL;
    if ((start_index = tstr_index_of(buf, tlist_get(split, 0)->value)) == -1) {
        tlist_free(split);
        return NULL;
    }
    if (split->length == 1)
        return buf + start_index;
    for (t_list_node *node = split->head->next; node; node = node->next) {
        if (tstr_index_of(buf, node->value) == -1) {
            tlist_free(split);
            return NULL;
        }
    }
    tlist_free(split);
    return buf + start_index;
}
