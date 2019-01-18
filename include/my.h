/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

# include <unistd.h>
# include <stdarg.h>

# define cmp(x, y, z) my_strncmp(x, y, z)
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define READ_SIZE 4096

typedef struct  linked_list_s
{
    void                    *data;
    struct linked_list_s    *next;
}               linked_list_t;

int     my_putchar(char c);
int     my_isneg (int nb);
int     my_put_nbr (int nb);
void    my_swap(int *a ,int *b);
int     my_putstr(char const *str);
int     my_strlen(char const *str);
int     my_getnbr(char const *str);
void    my_sort_int_array(int *tab, int size);
int     my_pow(int nb, int p);
int     my_compute_square_root(int nb);
int     my_is_prime(int nb);
int     my_find_prime_sup(int nb);
char    *my_strcpy(char *dest, char const *src);
char    *my_strncpy(char *dest , char const *src , int n);
char    *my_revstr(char *str);
char    *my_strstr(char *str, char const *to_find);
int     my_strcmp(char const *s1, char const *s2);
int     my_strncmp(char const *s1, char const *s2, int n);
char    *my_strupcase(char *str);
char    *my_strlowcase(char *str);
char    *my_strcapitalize(char *str);
int     my_str_isalpha(char const *str);
int     my_str_isnum(char const *str);
int     my_str_islower(char const *str);
int     my_str_isupper(char const *str);
int     my_str_isprintable(char const *str);
int     my_showstr(char const *str);
int     my_showmem(char const *str, int size);
char    *my_strcat(char *dest, char const *src);
char    *my_strncat(char *dest, char const *src, int nb);
int     my_show_word_array(char * const *tab);
char    **my_str_to_word_array(char const *str, char ch);
char    *my_strdup(char const *src);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
int     my_getnbr_base(char const *str, char const *base);
char    *my_int_tobase(int nb, char *base);
int     my_printf(char *str, ...);
int     putb(va_list list);
int     putd(va_list list);
int     putch(va_list list);
int     puto(va_list list);
int     putstr(va_list list);
int     putu(va_list list);
int     putx(va_list list);
int     putxm(va_list list);
int     put_float(va_list list, int p);
int     put_ptr(va_list list);
int     put_str_nprint(va_list list);
void    sort_list(linked_list_t **begin, int (*cmp)());
int     swap_ele(linked_list_t **ele1, linked_list_t **ele2, int (*cmp)());
void    rev_list(linked_list_t **begin);
linked_list_t   *params_to_list(int ac, char * const *av);
int     put_in_list(linked_list_t **list, void *data);
void    merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)());
int     list_size(linked_list_t const *begin);
linked_list_t   *find_node(linked_list_t const *begin,
void const *data_ref, int (*cmp)());
int     deletes_nodes(linked_list_t **begin, void const *data_ref,
int (*cmp)());
void    concat_list(linked_list_t **begin1, linked_list_t *begin2);
int     apply_on_nodes(linked_list_t *begin, int (*f)(void *));
int     apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
void const *data_ref, int (*cmp)());
void    add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());
char    *get_next_line(int fd);
double  my_getfloat(char const *str);
char    *my_itoa(int nb);

#endif
