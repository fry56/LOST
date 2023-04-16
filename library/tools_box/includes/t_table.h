/*
** EPITECH PROJECT, 2022
** ttable.c.h
** File description:
** desc
*/
#ifndef ttable
    #define ttable
    #include "t_ctype.h"
    #define table_len(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
    void free_table_dd(void **ptr, int len, bool free_seg);
#endif //ttable
