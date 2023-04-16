/*
** EPITECH PROJECT, 2023
** path_close_file.c
** File description:
** desc
*/

#include <t_path.h>
#include <unistd.h>
#include <t_mem.h>


void tpath_close_file(tfile_s *file)
{
    if (file == NULL)
        return;
    close(file->fd);
    free(file->path);
    free(file->buf);
    free(file);
}
