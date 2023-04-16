/*
** EPITECH PROJECT, 2022
** write.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <unistd.h>
#include <t_string.h>

tsize_t twrite(int fb, char *buffer)
{
    return (write(fb, buffer, tstr_len(buffer)));
}
