/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "sprites_structs.h"
#include "display_values.h"

static sfSprite *get_background(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale_bg = {1, 1};
    double bg_scale_factor = 0;
    double bg_ratio = (1.0 * BACKGROUND_WIDTH) / BACKGROUND_HEIGHT;

    if (sprite == NULL)
        return NULL;
    if (bg_ratio >= SCREEN_RATIO)
        bg_scale_factor = (1.0 * SCREEN_WIDTH) / BACKGROUND_WIDTH;
    else
        bg_scale_factor = (1.0 * SCREEN_HEIGHT) / BACKGROUND_HEIGHT;
    scale_bg.x = bg_scale_factor;
    scale_bg.y = bg_scale_factor;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale_bg);
    return sprite;
}

static bool_t set_sprites_textures(aircraft_t **planes, tower_t **towers)
{
    double plane_scale_factor = (1.0 * PLANE_SIZE) / PLANE_WIDTH;
    double tower_scale_factor = (1.0 * TOWER_SIZE) / TOWER_WIDTH;
    sfVector2f plane_scale_vector = {plane_scale_factor, plane_scale_factor};
    sfVector2f tower_scale_vector = {tower_scale_factor, tower_scale_factor};
    sfTexture *plane_texture = sfTexture_createFromImage(PLANE_PATH, NULL);
    sfTexture *tower_texture = sfTexture_createFromImage(TOWER_PATH, NULL);

    if (plane_texture == NULL || tower_texture)
        return FALSE;
    for (int i = 0; planes[i] != NULL; ++i) {
        sfSprite_setTexture((*planes[i]).sf_sprite, plane_texture, sfFalse);
        sfSprite_setScale((*planes[i]).sf_sprite, plane_scale_vector);
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        sfSprite_setTexture((*towers[i]).sf_sprite, tower_texture, sfFalse);
        sfSprite_setScale((*towers[i]).sf_sprite, tower_scale_vector);
    }
    return TRUE;
}

static sfTexture **get_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * (4));

    if (textures == NULL)
        return NULL;
    textures[0] = sfTexture_createFromImage(BACKGROUND_PATH, NULL);
    textures[1] = sfTexture_createFromImage(PLANE_PATH, NULL);
    textures[2] = sfTexture_createFromImage(TOWER_PATH, NULL);
    textures[3] = NULL;
    if (textures[0] == NULL || textures[1] == NULL) {
        if (textures[0] != NULL)
            sfTexture_destroy(textures[0]);
        if (textures[1] != NULL)
            sfTexture_destroy(textures[0]);
        if (textures[2] != NULL)
            sfTexture_destroy(textures[1]);
        free(textures);
        return NULL;
    }
    return textures;
}

static int radar_launch(aircraft_t **planes, tower_t **towers)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Radar",
        sfClose | sfTitlebar, NULL);
    sfTexture **textures = get_textures();
    sfSprite *background = NULL;

    if (textures == NULL)
        return EPITECH_ECHEC;
    background = get_background(textures[0]);
    if (background == NULL)
        return EPITECH_ECHEC;
    // sfRenderWindow_display(window);
    return EPITECH_SUCCESS;
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

static int check_arguments(int ac, char **av)
{
    if (ac <= 1) {
        my_putstr_error("my_radar: missing parameter\n");
        return EPITECH_ECHEC;
    }
    if (my_strcmp(av[1], "-h") == 0 ||
        (ac > 2 && my_strcmp(av[2], "-r") == 0)) {
        print_help();
        return EPITECH_SUCCESS;
    }
    return 1;
}

int main(int ac, char **av)
{
    char *path_to_script = NULL;
    void **script_data = NULL;
    aircraft_data_t **planes = NULL;
    tower_data_t **towers = NULL;
    int verif = check_arguments(ac, av);

    if (verif == EPITECH_ECHEC || verif == EPITECH_SUCCESS)
        return verif;
    path_to_script = av[ac - 1];
    script_data = get_script_data_content(path_to_script);
    if (script_data == NULL) {
        my_putstr_error("my_radar: can not get the script file data\n");
        return EPITECH_ECHEC;
    }
    planes = script_data[0];
    towers = script_data[1];
    if (set_sprites_textures(planes, towers) == FALSE)
        return EPITECH_ECHEC;
    return radar_launch(planes, towers);
}
