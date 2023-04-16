/*
** EPITECH PROJECT, 2022
** char_is_digits.c
** File description:
** desc
*/

int tchar_is_digit(char c)
{
    if (!(c >= '0' && c <= '9'))
        return 0;
    return 1;
}
