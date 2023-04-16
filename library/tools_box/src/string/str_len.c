/*
** EPITECH PROJECT, 2022
** str_len.c
** File description:
** desc
*/

int tstr_len(const char *buffer)
{
    register int count = 0;

    while (buffer[count] != '\0')
        count++;
    return count;
}
