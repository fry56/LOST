/*
** EPITECH PROJECT, 2023
** path_close_dir.c
** File description:
** desc
*/

#include <t_path.h>
#include <t_mem.h>
#include <t_string.h>


void tpath_close_dir(tdir_s *dir)
{
    list_foreach(dir->content, node)
        free(node->value);
    tlist_free(dir->content);
    free(dir->path);
    closedir(dir->dd);
    free(dir);
}
