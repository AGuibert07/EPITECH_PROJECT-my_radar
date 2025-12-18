/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to print the simulation report
*/

#include <stdio.h>
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
    my_putstr("-------Simulation Report-------\n");
    printf("\e[0;34m\n");
    printf("Towers :  %u\nPlanes :  %u\e[32m\n", report->tower_nbr,
        report->plane_nbr);
    printf("Arrived : %u\e[0;33m\nCrashed : %u\n", report->plane_arrived,
        report->plane_crashed);
    if (sum < report->plane_nbr)
        printf("\e[0;31mLost :    %u\e[0m\n", report->plane_nbr - sum);
}
