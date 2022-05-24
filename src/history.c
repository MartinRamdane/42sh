/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** history
*/

#include "my.h"

int print_history(char **arg)
{
    if (arg[1] && strcmp(arg[1], "-c") == 0) {
        int fd = open("/tmp/.42sh_history.txt", O_CREAT | O_WRONLY | O_TRUNC,
        S_IRUSR | S_IWUSR);
        close(fd);
        return 0;
    }
    int fd = open("/tmp/.42sh_history.txt", O_CREAT | O_RDONLY | O_APPEND,
    S_IRUSR | S_IWUSR);
    struct stat s;
    stat("/tmp/.42sh_history.txt", &s);
    char *history = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, history, s.st_size);
    history[s.st_size] = '\0';
    printf("%s", history);
    close(fd);
    free(history);
    return 0;
}

void add_in_history(char *cmd)
{
    int fd = open("/tmp/.42sh_history.txt", O_CREAT | O_WRONLY | O_APPEND,
    S_IRUSR | S_IWUSR);
    write(fd, cmd, strlen(cmd));
    close(fd);
}

char *do_exclamation(char *line, t_infos *infos)
{
    if (line[0] != '!')
        return line;
    FILE *fd = fopen("/tmp/.42sh_history.txt", "r");
    char *find = NULL;
    size_t size_len = 0;
    int i = 1, line_nbr = my_get_nbr_pos(line, 1);
    while (getline(&find, &size_len, fd) != -1) {
        if (i == line_nbr) {
            find[my_strlen(find) - 1] = '\0';
            fclose(fd);
            return find;
        }
        i++;
    }
    infos->return_val = 1;
    fclose(fd);
    return NULL;
}

// if !53356 > return 1 and  3563: Event not found.
