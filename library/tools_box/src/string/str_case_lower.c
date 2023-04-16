/*
** EPITECH PROJECT, 2022
** str_case_lower.c
** File description:
** desc
*/

char *tstr_case_lower(char *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] >= 'A' && str[count] <= 'Z')
            str[count] = str[count] + 32;
        count++;
    }
    return str;
}
