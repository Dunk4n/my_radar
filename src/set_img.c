/*
** EPITECH PROJECT, 2018
** set_img
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "my.h"
#include "radar.h"

const char *img_trans[5] = {"doc/hordzeplin.png", "doc/griffon.png",
"doc/tortue.png", "doc/bateau.png", "doc/boulet.png"};
const int size_img[5][3] = {{20, 20, 1}, {20, 20, 1}, {74, 70, 3}, {58, 95, 2},
{10, 10, 1}};

void    delete_dead(trans_t **tab)
{
    int i = 0;
    int j = 0;

    if (!tab)
        return ;
    while (tab[i]) {
        if (tab[i]->dead && tab[i]->tmp == -1) {
            j = 1;
            while (tab[i + j - 1]) {
                tab[i + j - 1] = tab[i + j];
                j++;
            }
        }
        i++;
    }
}

void    set_img(trans_t *trans, char **line, int nb, int name)
{
    int nbr = 0;

    trans->name = name;
    if (nb < 9 || my_getnbr(line[7]) < 0 || my_getnbr(line[7]) > 4)
        nbr = rand() % 4;
    else
        nbr = my_getnbr(line[7]);
    trans->tx = sfTexture_createFromFile(img_trans[nbr], NULL);
    trans->rect.width = size_img[nbr][0];
    trans->rect.height = size_img[nbr][1];
    trans->rectp.width = size_img[nbr][0];
    trans->rectp.height = size_img[nbr][1];
    trans->pv = size_img[nbr][2];
}
