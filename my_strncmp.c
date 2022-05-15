/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int run = 0;
    int run2 = 0;
    int result;
    while (s1[run] != '\0' && run != n) {
        if (s1[run] != s2[run2]) {
            result = s1[run] - s2[run2];
            return (result);
        }
        run = run + 1;
        run2 = run2 + 1;
    }
    return 0;
}
