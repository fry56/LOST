/*
** EPITECH PROJECT, 2023
** t_assert.h
** File description:
** desc
*/
#ifndef t_assert
    #define t_assert

    extern void l_assert_fail(char const *expr, char const *filename, \
    int line, void (*func)(char const *));

    #ifndef ASSERT_FUNCTION
        #define ASSERT_FUNCTION ((void *) 0)
    #endif

    #define tassert(expr) \
        if (expr) \
            l_assert_fail(#expr, __FILE__, __LINE__, ASSERT_FUNCTION);

#endif //t_assert
