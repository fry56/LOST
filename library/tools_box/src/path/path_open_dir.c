/*
** EPITECH PROJECT, 2023
** path_open_dir.c
** File description:
** desc
*/

#include <t_path.h>
#include <unistd.h>
#include <t_mem.h>
#include <t_string.h>
#include <dirent.h>
#include <t_assert.h>

static void read_content(tdir_s *new_dir)
{
    struct dirent *dirp;

    while ((dirp = readdir(new_dir->dd)))
        tlist_add(new_dir->content, tstr_cpy(NULL, dirp->d_name));
}

tdir_s *tpath_open_dir(char *path)
{
    tdir_s *new_dir;
    DIR *dd = opendir(path);

    if (dd == NULL)
        return NULL;
    t_assert((new_dir = tcalloc(1, sizeof(tdir_s))) == NULL);
    new_dir->dd = dd;
    new_dir->path = tstr_cpy(NULL, path);
    new_dir->content = tlist_new();
    read_content(new_dir);
    return new_dir;
}
