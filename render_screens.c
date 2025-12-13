/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_hunter
** File description:
** this file countains all functions to render the differently screens
*/

#include <SFML/Graphics.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "events_traitment.h"
#include "sprite_obj.h"
#include "create_window.h"
#include "render_screens.h"
#include "display_values.h"
#include "font.h"

int render_home_screen(sfRenderWindow *window,
    struct sprite_type *types_list)
{
    sfSprite *background = get_background(
        "assets/backgrounds/background-scratch.png", BG_SCRATCH_WIDTH,
        BG_SCRATCH_HEIGHT);

    if (background == NULL) {
        my_putstr_error("my_hunter: can't get the background image\n");
    }
    return EPITECH_SUCCESS;
    while (sfRenderWindow_isOpen(window)) {
        get_events(window, NULL, 0);
    }
    return EPITECH_SUCCESS;
}

static unsigned int get_nbr_ducks_alive(struct sprite_obj **duck_list,
    unsigned int duck_nbr)
{
    unsigned int nbr_alive = 0;

    for (int i = 0; i < duck_nbr; ++i) {
        if ((*duck_list[i]).status > 0)
            nbr_alive += 1;
    }
    return nbr_alive;
}

static struct sprite_obj **get_duck_list(sfRenderWindow *window,
    struct level_data *level, struct sprite_type *types_list)
{
    struct sprite_obj **duck_list =
        malloc(sizeof(struct sprite_obj *) * (*level).duck_nbr);
    struct sprite_type *duck_black = get_sprite_type(types_list, "duck_black");

    if (duck_list == NULL || duck_black == NULL)
        return NULL;
    for (int i = 0; i < (*level).duck_nbr; ++i) {
        duck_list[i] = sprite_obj_create(duck_black);
        if (duck_list[i] == NULL) {
            free(duck_list);
            return NULL;
        }
    }
    return duck_list;
}

static void update_duck_display(sfRenderWindow *window,
    struct level_data *level, struct sprite_obj **duck_list)
{
    for (int i = 0; i < (*level).duck_nbr; ++i) {
        if ((*duck_list[i]).status > 0) {
            duck_next_frame(duck_list[i], (*level).speed);
            sfRenderWindow_drawSprite(window, (*duck_list[i]).sf_sprite, NULL);
        }
    }
}

static char *get_score_str(unsigned int score)
{
    char *str = my_int_to_str_function(score, DIGITS);
    char *temp = NULL;

    if (str == NULL)
        return NULL;
    while (my_strlen(str) < 4) {
        temp = my_str_concat("0", str);
        if (temp == NULL)
            return NULL;
        free(str);
        str = temp;
    }
    return str;
}

static void render_level(sfRenderWindow *window, struct level_data *level,
    struct sprite_obj **duck_list, sfSprite *background)
{
    unsigned int nbr_alive = (*level).duck_nbr;
    char *score_str = NULL;

    while (sfRenderWindow_isOpen(window) && nbr_alive > 0) {
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, background, NULL);
        update_duck_display(window, level, duck_list);
        score_str = get_score_str((*level).score);
        if (score_str == NULL)
            return;
        text_obj_set_text((*level).score_obj, score_str);
        sf_render_window_draw_text_obj(window, (*level).score_obj, NULL);
        sfRenderWindow_display(window);
        get_events(window, duck_list, (*level).duck_nbr);
        nbr_alive = get_nbr_ducks_alive(duck_list, (*level).duck_nbr);
    }
}

static void free_structures(sfSprite *background,
    struct sprite_obj **duck_list, int duck_nbr)
{
    sfSprite_destroy(background);
    for (int i = 0; i < duck_nbr; ++i) {
        sprite_obj_destroy(duck_list[i]);
    }
    free(duck_list);
}

int render_level_screen(sfRenderWindow *window, struct level_data *level,
    struct sprite_type *types_list)
{
    sfSprite *background = NULL;
    struct sprite_obj **duck_list = get_duck_list(window, level, types_list);

    sfRenderWindow_clear(window, sfBlue);
    if (duck_list == NULL)
        return EPITECH_ECHEC;
    background = get_background("assets/backgrounds/background-official.png",
        BG_OFFICIAL_WIDTH, BG_OFFICIAL_HEIGHT);
    if (background == NULL)
        return EPITECH_ECHEC;
    sfRenderWindow_drawSprite(window, background, NULL);
    for (int i = 0; i < (*level).duck_nbr; ++i) {
        sfRenderWindow_drawSprite(window, (*duck_list[i]).sf_sprite, NULL);
    }
    sfRenderWindow_display(window);
    render_level(window, level, duck_list, background);
    free_structures(background, duck_list, (*level).duck_nbr);
    return EPITECH_SUCCESS;
}
