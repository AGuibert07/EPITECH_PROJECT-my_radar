/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to print the simulation report
*/

#include "report.h"
#include "my.h"

static void print_value(char *title, unsigned int value)
{
    my_putstr(title);
    my_put_nbr(value);
    my_putchar('\n');
}

void print_report(report_t *report)
{
    unsigned int sum = report->plane_arrived + report->plane_crashed;

    my_putstr("********Simulation Over********\n");
    my_putstr("-------Simulation Report-------\n\n");
    print_value("Towers :  ", report->tower_nbr);
    print_value("Planes :  ", report->plane_nbr);
    print_value("Arrived : ", report->plane_arrived);
    print_value("Crashed : ", report->plane_crashed);
    if (sum < report->plane_nbr)
        print_value("Lost :    ", report->plane_nbr - sum);
}
