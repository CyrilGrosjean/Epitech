/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string and return it
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char swap = '\0';
    int i = (my_strlen(str) - 1);
    int c = 0;

    while (i > c) {
        swap = str[c];
        str[c] = str[i];
        str[i] = swap;
        c++;
        i--;
    }
    return (str);
}
