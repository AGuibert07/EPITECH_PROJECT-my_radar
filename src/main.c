/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "script_data.h"

static int radar_launch(aircraft_data_t **planes, tower_data_t *towers)
{
    return EPITECH_SUCCESS;
}

/*static int radar_launch(void)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Hunter",
        sfClose | sfTitlebar, NULL);
    struct sprite_type *sprite_types = get_sprites_types();
    int level_r_value = 0;
    struct level_data *level = create_level_object();

    set_rand_start_stat();
    if (check_ptrs(sprite_types, window) != EPITECH_SUCCESS || level == NULL)
        return EPITECH_ECHEC;
    sfRenderWindow_display(window);
    for (; sfRenderWindow_isOpen(window); ++((*level).level_nbr)) {
        level_r_value = render_level_screen(window, level, sprite_types);
        if (level_r_value != EPITECH_SUCCESS)
            return exit_and_close(window);
    }
    free_structs(window, sprite_types, level);
    return EPITECH_SUCCESS;
}
*/
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

int main(int ac, char **av)
{
    char *path_to_script = NULL;
    void **script_data = NULL;

    if (ac <= 1) {
        my_putstr_error("my_radar: missing parameter\n");
        return EPITECH_ECHEC;
    }
    if (my_strcmp(av[1], "-h") == 0 ||
        (ac > 2 && my_strcmp(av[2], "-r") == 0)) {
        print_help();
        return EPITECH_SUCCESS;
    }
    path_to_script = av[ac - 1];
    script_data = get_script_data_content(path_to_script);
    if (script_data == NULL) {
        my_putstr_error("my_radar: can not get the script file data\n");
        return EPITECH_ECHEC;
    }
    // show_data(script_data);
    return radar_launch();
}
