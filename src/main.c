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
    my_printf("OPTIONS\n  -h\t\tprint the usage and quit.\n  -s\t\tprint the \
usage of the script and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("  'L' key\tenable/disable hitboxes and areas.\n");
    my_printf("  'S' key\tenable/disable sprites\n");
    return (0);
}

void    flag_s(void)
{
    my_printf("SCRIPT\n\n");
    my_printf("  The letter 'A'\n");
    my_printf("  Two integers corresponding to the departure x- and y- \
coordinates.\n  Two integers corresponding to the arrival x- and y-coordinates.\
\n  One float corresponding to the aircraft’s speed.\n  One integer \
corresponding to the delay (in seconds) before the aircraft takes off.\n  \
One integer for the model of aircraft's between 0-3.\n");
    my_printf("\n  The letter 'T'\n  Two integers corresponding to the control \
tower x- and y-coordinates\n  One integer corresponding to the radius of the \
tower’s control area (in pixel)\n");
    my_printf("\n  The letter 'S'\n  Two integers corresponding to the n \
x- and y-coordinates of one point of the storm.\n  You can have as much point \
as you want\n");
    my_printf("  You can test with:\n  S  960 420  1070 450  1120 600  \
1050 690  920 700  830 650  810 530  850 460\n");
    my_printf("\nEntities are separated by a '\\n'.\nThe pieces of information \
are separated by spaces.\n");
}

int     main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (flag_h());
    if (av[1][0] == '-' && av[1][1] == 's' && av[1][2] == '\0') {
        flag_s();
        return (0);
    }
    srand(time(NULL));
    return (map(av[1]));
}
