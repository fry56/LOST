/*
** EPITECH PROJECT, 2022
** str_contain.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_string.h>

bool tstr_contain_only(char *str, char *char_list)
{
    bool contain = false;
    int str_len = tstr_len(str);

    if (tstr_len(char_list) == 0)
        return false;
    for (int i = 0, j = 0; i < str_len; ++j) {
        if (char_list[j] == '\0' && !contain)
            return false;
        if (char_list[j] == '\0') {
            i++;
            j = 0;
            contain = false;
        }
        if (str[i] == char_list[j]) {
            contain = true;
        }
    }
    return true;
}
