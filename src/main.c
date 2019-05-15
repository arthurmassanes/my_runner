/*
** EPITECH PROJECT, 2018
** bootstrap my runner
** File description:
** main
*/

#include "my_runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int is_valid_map(char *map)
{
    int i;
    int line_1_len = 1;
    int nb_sharp = 0;

    for (int n = 0; map[n]; n++) {
        if (map[n] != ' ' && map[n] != '#' && map[n] != 'O' && map[n] != '\n') {
            write(2, "Error: not a valid map\nRetry with ./my_runner -h\n", 49);
            return (0);
        }
    }
    for (i = 0; map[i] != 0 && map[i] != '\n'; i++ && line_1_len++);
    i++;
    for (i; map[i] && map[i] != '\n'; i++)
        nb_sharp = (map[i] == '#' ? nb_sharp + 1 : nb_sharp);
    if (nb_sharp == line_1_len)
        return (1);
    else {
        write(2, "Error: not a valid map\nRetry with ./my_runner -h\n", 49);
        return (0);
    }
}

int file_size(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buf[2];
    int rd = -1;
    int sz = 0;

    while (rd != 0) {
        rd = read(fd, buf, 1);
        sz += rd;
    }
    close(fd);
    return (sz);
}

char *get_map(char *path)
{
    int rd = -1;
    int sz = file_size(path);
    int fd = open(path, O_RDONLY);
    char *map = malloc(sz * sizeof(char) + 1);

    if (fd == -1)
        return (NULL);
    read(fd, map, sz);
    close(fd);
    return (map);
}

int main(int ac, char **av, char *ae[])
{
    char *map;
    int fd;

    srand(time(NULL));
    if (!ae[0] || !ae[4] || ac != 2)
        return (EXIT_ERROR);
    else if (my_cmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (EXIT_ERROR);
    close(fd);
    map = get_map(av[1]);
    if (is_char(map, 'O') == 0 || !is_valid_map(map))
        return (EXIT_ERROR);
    menu(map);
    free(map);
    return (0);
}
