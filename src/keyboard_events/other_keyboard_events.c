/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains the keyboard events functions to enable/disable elements
*/

#include "my.h"
#include "events_traitment.h"

int e_touch(event_arguments_t *arguments)
{
    arguments->close_at_end = NOT(arguments->close_at_end);
    return EPITECH_SUCCESS;
}
