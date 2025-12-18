/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "sprites_structs.h"
#include "display_values.h"
#include "render_screen.h"
#include "textures.h"
#include "arguments.h"

static void free_elements(sfRenderWindow *window, textures_versions_t *textures,
    void **script_data, sfSprite *background)
{
    aircraft_t **planes = script_data[0];
    tower_t **towers = script_data[1];

    sfRenderWindow_destroy(window);
    textures_versions_destroy(textures);
    for (int i = 0; planes[i] != NULL; ++i) {
        sfSprite_destroy((*planes[i]).sf_sprite);
        free(planes[i]);
    }
    free(planes);
    for (int i = 0; towers[i] != NULL; ++i) {
        sfSprite_destroy((*towers[i]).sf_sprite);
        free(towers[i]);
    }
    free(towers);
    sfSprite_destroy(background);
}

static int radar_launch(void **script_data, textures_versions_t *textures)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Radar",
        sfClose | sfTitlebar, NULL);
    sfSprite *background = NULL;
    int r_val = 0;

    background = get_background(textures);
    if (background == NULL)
        return EPITECH_ECHEC;
    r_val = render_radar(window, background, script_data, textures);
    free_elements(window, textures, script_data, background);
    return r_val;
}

static void print_help(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("    path_to_script    The path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L' key        enable/disable hitboxes and areas.\n");
    my_putstr("  'S' key        enable/disable sprites.\n");
    my_putstr("  'T' key        enable/disable planes trajectories.\n");
    my_putstr("  'B' key        switch the background image\n");
    my_putstr("  'P' key        switch the planes image\n");
    my_putstr("  'C' key        switch the control towers image\n");
    my_putstr("  'Q' or 'escape' key        quit\n");
}

static int show_data(void **data)
{
    aircraft_data_t **planes = data[0];
    tower_data_t **towers = data[1];

    my_putstr("aircrafts :\n");
    for (int i = 0; planes[i] != NULL; ++i) {
        my_putchar('\t');
        aircraft_data_print(planes[i]);
        my_putchar('\n');
    }
    my_putstr("\ncontrol towers:\n");
    for (int i = 0; towers[i] != NULL; ++i) {
        my_putchar('\t');
        tower_data_print(towers[i]);
        my_putchar('\n');
    }
    return EPITECH_SUCCESS;
}

static arguments_verif_t check_arguments(int ac, char **av)
{
    if (ac <= 1) {
        my_putstr_error("my_radar: missing parameter\n");
        return INVALID_ARGS;
    } else if (my_strcmp(av[1], "-h") == 0 ||
        (ac > 2 && my_strcmp(av[2], "-r") == 0)) {
        print_help();
        return HELP_OPTION;
    }
    return VALID_ARGS;
}

int main(int ac, char **av)
{
    char *path_to_script = NULL;
    void **script_data = NULL;
    arguments_verif_t verif = check_arguments(ac, av);
    textures_versions_t *textures = get_textures();

    if (textures == NULL)
        return EPITECH_ECHEC;
    if (verif != VALID_ARGS)
        return verif;
    path_to_script = av[ac - 1];
    script_data = get_script_data_content(path_to_script);
    if (script_data == NULL) {
        my_putstr_error("my_radar: can not get the script file data\n");
        return EPITECH_ECHEC;
    }
    if (!set_textures_and_pos(script_data[0], script_data[1], textures)) {
        my_putstr_error("my_radar: can not get textures\n");
        return EPITECH_ECHEC;
    }
    return radar_launch(script_data, textures);
}
