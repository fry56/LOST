/*
** EPITECH PROJECT, 2022
** calloc.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <t_mem.h>
#include <t_assert.h>

void *tcalloc(tsize_t tmem, tsize_t size)
{
    void *pointer = malloc(size * tmem);

    tassert(pointer == NULL);
    if (pointer)
        tmemset(pointer, 0, size * tmem);
    return pointer;
}
