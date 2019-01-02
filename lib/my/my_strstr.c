/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find the first occurrence of the substring in a string
*/

int     my_strncmp(char const *s1, char const *s2, int n);
int     my_strlen(char const *str);

char    *my_strstr(char const *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(to_find);

    while (str[i] != '\0') {
        if (str[i] == to_find[0] && my_strncmp(&str[i], to_find, len) == 0) {
            return (char*)(str + i);
        }
        i++;
    }
    return (0);
}
