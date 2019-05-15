/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** function for displaying help
*/

#include "my_runner.h"

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen(str) + 1);
    int i;

    if (!str)
        return (NULL);
    for (i = 0; str[i]; i++)
        dup[i] = str[i];
    dup[i] = 0;
    return (dup);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int my_cmp(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (-1);
    for (int i = 0; s1[i]; i++) {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void print_help(void)
{
    my_putstr("  _ __ ___  _   _     _ __ _   _ _ __  _ __   ___ _ __ \n");
    my_putstr(" | '_ ` _ \\| | | |   | '__| | | | '_ \\| '_ \\ / _ \\ '__|\n");
    my_putstr(" | | | | | | |_| |   | |  | |_| | | | | | | |  __/ |   \n");
    my_putstr(" |_| |_| |_|\\__, |   |_|   \\__,_|_| |_|_| |_|\\___|_|   \n");
    my_putstr("             __/ |                                     \n");
    my_putstr("            |___/                                      \n");
    my_putstr("\nFinite runner created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_runner\tmap.txt\n\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h\t\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" SPACE KEY\tjump; press and hold to glide.\n\n");
    my_putstr("MAP:\n Simple text file. Read the .legend file.\n\n");
}
