/*
** EPITECH PROJECT, 2023
** t_path.h
** File description:
** desc
*/
#ifndef t_path
    #define t_path

    #include <t_ctype.h>
    #include <dirent.h>
    #include <t_list.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>

    typedef struct tfile_t {
        int fd;
        char *path;
        tsize_t size;
        char *buf;
        tsize_t lignes;
    } tfile_s;

    typedef struct tdir_t {
        DIR *dd;
        char *path;
        t_list *content;
    } tdir_s;

    tfile_s *tpath_open_file(char *path, int flags, bool buff);
    void tpath_close_file(tfile_s *file);

    tdir_s *tpath_open_dir(char *path);
    void tpath_close_dir(tdir_s *dir);

    bool tpath_is_valide(char *path);
    t_list *tpath_file_content_to_array(tfile_s *file);
#endif //t_path
