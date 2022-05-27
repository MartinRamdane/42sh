/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-42sh-martin.ramdane
** File description:
** get_alias
*/

#include "my.h"

char *get_alias(char *line, t_infos *infos)
{
    char *new_line = NULL;
    t_alias *temp = infos->alias;
    while (temp) {
        if (my_strstr(line, temp->alias)) {
            new_line = update_line_alias(line, temp->alias, temp->command);
            printf("%s\n", new_line);
            return new_line;
        }
        temp = temp->next;
    }
    return line;
}

char *update_line_alias(char *line, char *alias, char *command)
{
    int i = 0;
    char *pointer = strstr(line, alias);
    char *new_line = malloc(sizeof(char) * (my_strlen(line) + 1 +
    my_strlen(command) + 1));
    my_memset(new_line, 0, my_strlen(line) + my_strlen(command) + 1);
    char *new_lineptr = new_line;
    while (*line) {
        if (!strncmp(line, alias, strlen(alias))) {
            strcat(new_lineptr, command);
            line += strlen(alias);
            new_lineptr += strlen(command);
        } else {
            *new_lineptr = *line;
            new_lineptr++;
            line++;
        }
    }
    *new_lineptr = '\0';
    return new_line;
}
