/*
** EPITECH PROJECT, 2022
** tmem.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TMEM_H
    #define TOOLS_BOX_TMEM_H
    #include "t_ctype.h"
    #include <stdlib.h>
    void *tmemset(void *dest, int value, tsize_t size);
    void *tmemmove(void *dest, const void *src, tsize_t size);
    void *tmemcpy(void *dest, const void *src, tsize_t size);
    void *tcalloc(tsize_t tmem, tsize_t size);
    void *trealloc(void *tmem, tsize_t size, tsize_t new_size);
    char *tdata_to_binary(void *data, tsize_t size);
#endif //TOOLS_BOX_TMEM_H
