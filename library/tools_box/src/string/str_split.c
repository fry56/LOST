/*
** EPITECH PROJECT, 2022
** str_to_tlist.c
** File description:
** desc
*/

#include <t_list.h>
#include <stdlib.h>
#include <t_mem.h>
#include <t_string.h>
#include <t_hashmap.h>

static bool is_char_split(char c, char *split)
{
    if (c == '\0')
        return true;
    for (int i = 0; split[i] != '\0'; i++){
        if (split[i] == c)
            return true;
    }
    return false;
}

t_list *tstr_split(char *buf, char *split)
{
    t_list *new_list = tlist_new();
    int str_size = 0;
    char *temp;
    int buf_len = tstr_len(buf);
    for (int i = 0; buf_len >= i; ++i) {
        if (is_char_split(buf[i], split) || buf_len == i) {
            temp[str_size] = '\0';
            tlist_add(new_list, temp);
            str_size = 0;
            continue;
        }
        if (str_size == 0)
            temp = malloc(2);
        else
            temp = trealloc(temp, str_size + 1, str_size + 2);
        temp[str_size] = buf[i];
        str_size++;
    }
    return new_list;
}

static bool is_string_split(int *i, const char *buf
        , const int split_length, const char **split)
{
    int index_split = 0;
    int index_buf = *i;

    for (int j = 0; j < split_length ;) {
        if (split[j][index_split] == '\0') {
            *i += (index_buf - *i) - 1;
            return true;
        }
        if (buf[index_buf] == split[j][index_split]) {
            index_split++;
            index_buf++;
            continue;
        }
        j++;
        index_split = 0;
        index_buf = *i;
    }
    return false;
}

t_list *tstr_split_list(const char *buf, const int split_length
        , const char **split)
{
    t_list *new_list;
    int buf_lenght = tstr_len(buf);
    char *temp_buf = malloc(buf_lenght + 1);
    int temp_buf_index = 0;

    if ((new_list = tlist_new()) == NULL)
        return NULL;
    for (int i = 0; i <= buf_lenght; ++i) {
        if (is_string_split(&i, buf, split_length, split)
            || i == buf_lenght) {
            temp_buf[temp_buf_index++] = '\0';
            tlist_add(new_list, temp_buf);
            temp_buf = malloc(buf_lenght + 1);
            temp_buf_index = 0;
            continue;
        }
        temp_buf[temp_buf_index++] = buf[i];
    }
    return new_list;
}
