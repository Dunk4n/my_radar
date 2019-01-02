/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** sort an array
*/

void    swa(int i, int *array, int *bol)
{
    if (array[i] > array[i + 1]) {
        array[i] += array[i + 1];
        array[i + 1] = array[i] - array[i + 1];
        array[i] -= array[i + 1];
        *bol = 1;
    }
}

void    my_sort_int_array(int *array, int size)
{
    int i = 0;
    int bol = 1;

    if (size <= 1)
        return ;
    while (bol == 1) {
        bol = 0;
        while (i < size - 1) {
            swa(i, array, &bol);
            i++;
        }
        i = 0;
    }
}
