/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** history
*/

#include "my.h"

int get_nb_lignes_history(void)
{
    int result = 0;
    FILE *fd = fopen("/tmp/.42sh_history.txt", "r");
    char *find = NULL;
    size_t size_len = 0;
    while (getline(&find, &size_len, fd) != -1)
        result++;
    return result;
}

void clear_history(void)
{
    int fd = open("/tmp/.42sh_history.txt", O_CREAT | O_WRONLY | O_TRUNC,
    S_IRUSR | S_IWUSR);
    close(fd);
}

int print_history(char **arg)
{
    if (arg[1] && strcmp(arg[1], "-c") == 0) {
        clear_history(); return 0;
    }
    if (arg[1] && strcmp(arg[1], "-h") == 0) {
        history_h(); return 0;
    }
    FILE *fd = fopen("/tmp/.42sh_history.txt", "r+");
    char *history = NULL;
    size_t size_len = 0;
    int i = 1;
    while (getline(&history, &size_len, fd) != -1) {
        printf("%i %s", i, history);
        i++;
    }
    fclose(fd);
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
    printf("%i: Event not found.", line_nbr);
    infos->return_val = 1; fclose(fd);
    return NULL;
}
