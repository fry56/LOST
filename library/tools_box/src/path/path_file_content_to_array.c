/*
** EPITECH PROJECT, 2023
** path_file_content_to_array.c
** File description:
** desc
*/

#include <t_path.h>
#include <unistd.h>
#include <t_string.h>

t_list *tpath_file_content_to_array(tfile_s *file)
{
    t_list *array = tlist_new();
    int start_index = 0;
    int end_index = 0;

    if (array == NULL)
        return NULL;
    for (char *cpy = file->buf; *cpy; cpy++, end_index++) {
        if (*cpy == '\n') {
            tlist_add(array, tstr_ncpy(NULL,
                (cpy - (end_index - start_index)),
                (end_index - start_index)));
            start_index = end_index + 1;
        }
    }
    tlist_add(array, tstr_cpy(NULL, (file->buf + start_index)));
    return array;
}
