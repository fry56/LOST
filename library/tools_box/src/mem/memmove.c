/*
** EPITECH PROJECT, 2022
** memmove.c
** File description:
** desc
*/

#include <t_ctype.h>

void *tmemmove(void *dest, const void *src, tsize_t size)
{
    const u8 *src_pointer = (u8 *)src;
    u8 *dest_pointer = (u8 *)dest;

    if (src_pointer < dest_pointer) {
        src_pointer += size;
        dest_pointer += size;
        while (--size > 0)
            *--dest_pointer = *--src_pointer;
    } else {
        while (--size > 0)
            *dest_pointer++ = *src_pointer++;
    }
    return dest;
}
