/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** env_utils
*/

#include "my.h"

int delete_elem(char **env, int pos)
{
    int i = 0;
    for (; env[i] != NULL; i++);
    for (int y = pos; y < i ; y++) {
        env[y] = env[y + 1];
    }
    env[i - 1] = NULL;
    env[i] = NULL;
}

int check_env(char **env, char *arg)
{
    for (int z = 0; env[z] != NULL; z++) {
        if (my_strncmp(env[z], arg, my_strlen(arg)) == 0) {
            delete_elem(env, z);
            return 0;
        }
    }
}
