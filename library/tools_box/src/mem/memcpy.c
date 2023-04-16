/*
** EPITECH PROJECT, 2022
** memcpy.c
** File description:
** desc
*/

#include <t_ctype.h>

void *tmemcpy(void *dest, const void *src, tsize_t size)
{
    const u8 *sp;
    u8 *dp;

    if (dest == NULL || src == NULL)
        return NULL;
    sp = (const u8 *)src;
    dp = (u8 *)dest;
    while (size) {
        *dp++ = *sp++;
        size--;
    }
    return dest;
}
