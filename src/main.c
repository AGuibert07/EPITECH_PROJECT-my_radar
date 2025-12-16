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

static sfSprite *get_background(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale_bg = {1, 1};
    double bg_scale_factor = 0;
    sfVector2f position = {1, 1};

    if (sprite == NULL)
        return NULL;
    if (((1.0 * BACKGROUND_WIDTH) / BACKGROUND_HEIGHT) >= SCREEN_RATIO)
        bg_scale_factor = (1.0 * SCREEN_WIDTH) / BACKGROUND_WIDTH;
    else
        bg_scale_factor = (1.0 * SCREEN_HEIGHT) / BACKGROUND_HEIGHT;
    scale_bg.x = bg_scale_factor;
    scale_bg.y = bg_scale_factor;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale_bg);
    position.x = (SCREEN_WIDTH - (BACKGROUND_WIDTH * bg_scale_factor)) / 2.0;
    position.y = (SCREEN_HEIGHT - (BACKGROUND_HEIGHT * bg_scale_factor)) / 2.0;
    sfSprite_setPosition(sprite, position);
    return sprite;
}

static bool_t set_sprites_boxes(aircraft_t **planes, tower_t **towers)
{
    sfVector2f size = {PLANE_BOX_SIZE, PLANE_BOX_SIZE};
    sfColor plane_box_color = sfColor_fromRGB(252, 220, 119);
    sfColor tower_box_color = sfColor_fromRGB(186, 217, 165);

    for (int i = 0; planes[i] != NULL; ++i) {
        sfRectangleShape_setSize((*planes[i]).box, size);
        sfRectangleShape_setRotation((*planes[i]).box,
            DEGREE_TO_RAD((*planes[i]).orientation));
        sfRectangleShape_setOutlineColor((*planes[i]).box, plane_box_color);
        sfRectangleShape_setOutlineThickness((*planes[i]).box, BOX_LINE_SIZE);
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        sfCircleShape_setRadius((*towers[i]).zone, (*towers[i]).area_radius);
        sfCircleShape_setOutlineColor((*towers[i]).zone, tower_box_color);
        sfCircleShape_setOutlineThickness((*towers[i]).zone, BOX_LINE_SIZE);
    }
    return TRUE;
}

static bool_t set_sprites_textures(aircraft_t **planes, tower_t **towers)
{
    double plane_scale_factor = (1.0 * PLANE_SIZE) / PLANE_WIDTH;
    double tower_scale_factor = (1.0 * TOWER_SIZE) / TOWER_WIDTH;
    sfVector2f plane_scale_vector = {plane_scale_factor, plane_scale_factor};
    sfVector2f tower_scale_vector = {tower_scale_factor, tower_scale_factor};
    sfTexture *plane_texture = sfTexture_createFromFile(PLANE_PATH, NULL);
    sfTexture *tower_texture = sfTexture_createFromFile(TOWER_PATH, NULL);

    if (plane_texture == NULL || tower_texture == NULL)
        return FALSE;
    for (int i = 0; planes[i] != NULL; ++i) {
        sfSprite_setTexture((*planes[i]).sf_sprite, plane_texture, sfFalse);
        sfSprite_setScale((*planes[i]).sf_sprite, plane_scale_vector);
        sfSprite_setRotation((*planes[i]).sf_sprite,
            DEGREE_TO_RAD((*planes[i]).orientation));
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        sfSprite_setTexture((*towers[i]).sf_sprite, tower_texture, sfFalse);
        sfSprite_setScale((*towers[i]).sf_sprite, tower_scale_vector);
    }
    return set_sprites_boxes(planes, towers);
}

static sfTexture **get_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * (5));

    if (textures == NULL)
        return NULL;
    textures[0] = sfTexture_createFromFile(BACKGROUND_PATH, NULL);
    textures[1] = sfTexture_createFromFile(PLANE_PATH, NULL);
    textures[2] = sfTexture_createFromFile(TOWER_PATH, NULL);
    textures[3] = sfTexture_createFromFile(CRASH_PATH, NULL);
    textures[4] = NULL;
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

static void free_elements(sfRenderWindow *window, sfTexture **textures,
    void **script_data, sfSprite *background)
{
    aircraft_t **planes = script_data[0];
    tower_t **towers = script_data[1];

    sfRenderWindow_destroy(window);
    for (int i = 0; textures[i] != NULL; ++i) {
        sfTexture_destroy(textures[i]);
    }
    free(textures);
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

static int radar_launch(void **script_data)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Radar",
        sfClose | sfTitlebar, NULL);
    sfTexture **textures = get_textures();
    sfSprite *background = NULL;
    int r_val = 0;

    if (textures == NULL)
        return EPITECH_ECHEC;
    background = get_background(textures[0]);
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
    int verif = check_arguments(ac, av);

    if (verif == EPITECH_ECHEC || verif == EPITECH_SUCCESS) {
        if (verif != EPITECH_SUCCESS)
            my_putstr_error("my_radar: invalid parameters\n");
        return verif;
    }
    path_to_script = av[ac - 1];
    script_data = get_script_data_content(path_to_script);
    if (script_data == NULL) {
        my_putstr_error("my_radar: can not get the script file data\n");
        return EPITECH_ECHEC;
    }
    if (set_sprites_textures(script_data[0], script_data[1]) == FALSE) {
        my_putstr_error("my_radar: can not get textures\n");
        return EPITECH_ECHEC;
    }
    return radar_launch(script_data);
}
