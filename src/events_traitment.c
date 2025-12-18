/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to get and trait events
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "textures.h"
#include "events_traitment.h"

static int get_keyboard_events(sfEvent *event, sfRenderWindow *window,
    event_arguments_t *arguments)
{
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyL)
        arguments->show_boxes = NOT(arguments->show_boxes);
    if (event->key.code == sfKeyS)
        arguments->show_sprites = NOT(arguments->show_sprites);
    if (event->key.code == sfKeyT)
        arguments->show_trajectories = NOT(arguments->show_trajectories);
    if (event->key.code == sfKeyP)
        update_plane_texture(arguments->script_data[0], arguments->textures);
    if (event->key.code == sfKeyC)
        update_tower_texture(arguments->script_data[1], arguments->textures);
    if (event->key.code == sfKeyB)
        update_background_texture(arguments->background, arguments->textures);
    return EPITECH_SUCCESS;
}

int check_event_traitment_result(int r_val, sfRenderWindow *window)
{
    if (r_val != EPITECH_SUCCESS)
        sfRenderWindow_close(window);
    return r_val;
}

int get_events(sfRenderWindow *window, event_arguments_t *arguments)
{
    sfEvent event;
    int r_val = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return EPITECH_SUCCESS;
        }
        if (event.type == sfEvtKeyPressed)
            return check_event_traitment_result(get_keyboard_events(&event,
                    window, arguments), window);
    }
    return EPITECH_SUCCESS;
}
