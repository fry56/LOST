/*
** EPITECH PROJECT, 2022
** tprintf_function.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TPRINT_H
    #define TOOLS_BOX_TPRINT_H
    #include <stdarg.h>
    void string_flag(va_list args);
    void char_flag(va_list args);
    void modulo_flag(va_list args);
    void int_flag(va_list args);
    void float_flags(va_list args);
    int tprintf(char *format, ...);
#endif //TOOLS_BOX_TPRINT_H
