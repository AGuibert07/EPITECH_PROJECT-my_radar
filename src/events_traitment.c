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

static void l_touch(event_arguments_t *arguments)
{
    arguments->show_boxes = NOT(arguments->show_boxes);
}

static void s_touch(event_arguments_t *arguments)
{
    arguments->show_sprites = NOT(arguments->show_sprites);
}

static void t_touch(event_arguments_t *arguments)
{
    arguments->show_trajectories = NOT(arguments->show_trajectories);
}

static void a_touch(event_arguments_t *arguments)
{
    arguments->show_crash = NOT(arguments->show_crash);
}

static void p_touch(event_arguments_t *arguments)
{
    update_plane_texture(arguments->script_data[0], arguments->textures);
}

static void c_touch(event_arguments_t *arguments)
{
    update_tower_texture(arguments->script_data[1], arguments->textures);
}

static void b_touch(event_arguments_t *arguments)
{
    update_background_texture(arguments->background, arguments->textures);
}

static int get_keyboard_events(sfEvent *event, sfRenderWindow *window,
    event_arguments_t *arguments)
{
    sfKeyCode key_codes[NBR_TOUCH_EVENTS - 1] = {sfKeyL, sfKeyS, sfKeyT,
        sfKeyP, sfKeyC, sfKeyB, sfKeyA};
    void (*functions[NBR_TOUCH_EVENTS - 1])(event_arguments_t *) = {&l_touch,
        &s_touch, &t_touch, &p_touch, &c_touch, &b_touch, &a_touch};
    key_touch_t *elt = NULL;

    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ) {
        sfRenderWindow_destroy(window);
        return EPITECH_SUCCESS;
    }
    for (int i = 0; i < (NBR_TOUCH_EVENTS - 1); ++i) {
        if (event->key.code == key_codes[i]) {
            functions[i](arguments);
            return EPITECH_SUCCESS;
        }
    }
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
