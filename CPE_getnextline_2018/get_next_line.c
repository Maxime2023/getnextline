/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** get next line
*/

#include "get_next_line.h"

int    len(char *str)
{
    int a = 0;

    if (str == NULL)
        return (0);
    else {
        while (str[a] != '\0')
            a++;
    }
    return (a);
}

char    *my_strcat(char *str, char *str_two)
{
    int a = 0;
    int b = 0;
    char *final_str = malloc(sizeof(char) * (len(str) + len(str_two)) + 3);

    if (str == NULL) {
        for (; str_two[a] != '\0'; a++)
            final_str[a] = str_two[a];
        final_str[a] = '\0';
    }
    else {
        for (; str[a] != '\0'; a++)
            final_str[a] = str[a];
        for (; str_two[b] != '\0'; b++) {
            final_str[a] = str_two[b];
            a++;
        }
        final_str[a] = '\0';
    }
    return (final_str);
}

int    seeking_end_of_line(char *str)
{
    int a = 0;

    if (str == NULL)
        return (0);
    while (str[a]) {
        if (str[a] == '\n')
            return (1);
        a++;
    }
    return (0);
}

char    *filling_str(char *tab, char *final)
{
    int a = 0;
    int d = 0;
    int f = 0;
    char *str = malloc(sizeof(char) * 1000);

    if (final[0] != '\0')
        str = my_strcat(final, str);
    for (; str[a]; a++);
    for (; tab[f] != '\n'; f++) {
        str[a] = tab[f];
        a++;
    }
    str[a] = '\0';
    f++;
    for (; tab[f] != '\0'; f++) {
        final[d] = tab[f];
        d++;
    }
    final[d] = '\0';
    return (str);
}

char    *get_next_line(int fd)
{
    static char final[1000];
    int a = 0;
    char *buf = malloc(sizeof(char) * READ_SIZE + 1);
    char *save = NULL;
    char *tmp = NULL;

    while (seeking_end_of_line(tmp) != 1) {
        a = read(fd, buf, READ_SIZE);
        if (a <= 0)
            return (NULL);
        buf[a] = '\0';
        tmp = my_strcat(tmp, buf);
    }
    save = filling_str(tmp, final);
    return (save);
}
