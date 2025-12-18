/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all events traitment tools
*/

#ifndef REPORT_
    #define REPORT_

struct report {
    unsigned int tower_nbr;
    unsigned int plane_nbr;
    unsigned int plane_arrived;
    unsigned int plane_crashed;
} typedef report_t;

void print_report(report_t *report);

#endif /* REPORT_ */
