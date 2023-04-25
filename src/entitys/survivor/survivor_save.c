/*
** EPITECH PROJECT, 2023
** survivor_save.c
** File description:
** desc
*/

#include <survivor/survivor.h>
#include <t_path.h>
#include <fcntl.h>
#include <paths.h>

void survivor_save(survivor_s *survivor_data)
{
    survivor_save_s save;
    int fd;

    save.xp = survivor_data->xp;
    save.health_level = survivor_data->health_level;
    save.health = survivor_data->health;
    save.speed_level = survivor_data->speed_level;
    save.speed = survivor_data->speed;
    if ((fd = open(save_path, O_CREAT | O_WRONLY)) == -1)
        return;
    write(fd, &save, sizeof(survivor_save_s));
    close(fd);
}

bool survivor_have_save(void)
{
    int fd = open(save_path, O_RDONLY);
    close(fd);
    return (fd == -1 ? false : true);
}

void survivor_load_save(survivor_s *survivor_data)
{
    survivor_save_s save;
    int fd;

    if ((fd = open(save_path, O_RDWR)) == -1)
        return;
    if (read(fd, &save, sizeof(survivor_save_s)) == -1)
        return;
    survivor_data->xp = save.xp;
    survivor_data->health_level = save.health_level;
    survivor_data->health = save.health;
    survivor_data->speed_level = save.speed_level;
    survivor_data->speed = save.speed;
}
