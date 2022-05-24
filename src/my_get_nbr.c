/*
** EPITECH PROJECT, 2021
** my_get_nbr
** File description:
** my_get_nbr for evaluation
*/

int my_get_nbr(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0' ) {
        while (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i = i + 1;
        }
    }
    return nb;
}
