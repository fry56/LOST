/*
** EPITECH PROJECT, 2023
** xml_load.c
** File description:
** desc
*/

#include <t_xml_token.h>
#include <t_mem.h>
#include <t_assert.h>
#include <t_path.h>
#include <t_string.h>

t_xml *t_xml_load(const char *path)
{
    t_xml *doc = tcalloc(1, sizeof(t_xml));
    tfile_s *file = tpath_open_file((char *)path, O_RDONLY, true);
    int skipe_xml_header;
    char *temp = file->buf;

    tassert(doc == NULL || file == NULL);
    if (doc == NULL || file == NULL)
        return NULL;
    doc->root = t_xml_new_node(NULL);
    skipe_xml_header = tstr_index_of(file->buf, "?>");
    temp += skipe_xml_header > 0 ? skipe_xml_header + 2 : 0;
    if (!t_xml_token_parser(doc, temp)) {
        t_xml_free(doc);
        return NULL;
    }
    tpath_close_file(file);
    return doc;
}
