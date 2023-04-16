/*
** EPITECH PROJECT, 2022
** str_case_upper.c
** File description:
** desc
*/

char *tstr_case_upper(char *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] >= 'a' && str[count] <= 'z')
            str[count] = str[count] - 32;
        count++;
    }
    return str;
}
