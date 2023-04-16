/*
** EPITECH PROJECT, 2022
** str_str.c
** File description:
** desc
*/

char *tstr_str(char *str, char const *to_find)
{
    int count = 0;
    int index_find = 0;

    while (str[count] != '\0') {
        if (str[count] == to_find[index_find]) {
            index_find++;
        } else {
            index_find = 0;
        }
        if (to_find[index_find] == '\0') {
            return (&str[count - index_find]);
        }
        count++;
    }
    return 0;
}
