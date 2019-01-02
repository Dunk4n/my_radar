/*
** EPITECH PROJECT, 2018
** main
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "radar.h"

int     flag_h(void)
{
    my_printf("Air traffic simulation panel\n\n");
    my_printf("USAGE\n  ./my_radar [OPTIONS] path_to_script\n");
    my_printf("  path_to_script    The path to the script file.\n\n");
    my_printf("OPTIONS\n  -h\t\tprint the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("  'L' key\tenable/disable hitboxes and areas.\n");
    my_printf("  'S' key\tenable/disable sprites\n");
    return (0);
}

int     main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (flag_h());
    srand(time(NULL));
    return (map(av[1]));
}
