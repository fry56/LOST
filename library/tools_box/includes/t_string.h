/*
** EPITECH PROJECT, 2022
** tstring.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TSTRING_H
    #define TOOLS_BOX_TSTRING_H
    #include "t_ctype.h"
    #include <t_list.h>
    char *tstr_case_lower(char *str);
    char *tstr_case_upper(char *str);
    int tstr_cmp(char const *s1, char const *s2);
    int tstr_ncmp(char const *s1, char const *s2, int n);
    char *tstr_cpy(char *dest, char const *src);
    char *tstr_ncpy(char *dest, char const *src, int n);
    int tstr_is_alpha(char const *str);
    int tstr_is_lower(char const *str);
    int tstr_is_num(char const *str);
    int tstr_is_printable(const char *str);
    int tstr_is_upper(char const *str);
    int tstr_len(char const *buffer);
    char *tstr_rev(char *str);
    char *tstr_str(char *str, char const *to_find);
    bool tstr_contain_only(char *str, char *char_list);
    char *tstr_concat(char *str_a, char *str_b);
    char *tstr_n_concat(char *str_a, char *str_b, int len_b);
    char *tstr_number(int number);
    int tstr_to_number(char *number);
    t_list *tstr_split(char *buf, char *split);
    t_list *tstr_split_list(const char *buf, const int split_length
            , const char **split);
    char *tstr_concat_char(char *str_a, char char_b);
    char *tstr_to_binary(char *str);
    char *tbinary_to_str(char *binary);
    char *tstr_compos(char *format, ...);
    int tstr_index_of(char *buf, char *value);
    char *tstr_match(char *buf, char *match);
#endif //TOOLS_BOX_TSTRING_H
