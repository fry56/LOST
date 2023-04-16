/*
** EPITECH PROJECT, 2023
** path_is_valide.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <fcntl.h>
#include <unistd.h>

bool tpath_is_valide(char *path)
{
    int fd = open(path, O_RDWR);
    close(fd);
    return fd == -1 ? false : true;
}
