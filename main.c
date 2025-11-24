/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_hunter
** File description:
** main file of the project
*/

#include <SFML/Graphics.h>
#include "my.h"

static int game_launch(void)
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

int main(int ac, char **av)
{
    if (ac > 1) {
        if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
            print_help();
            return EPITECH_SUCCESS;
        } else {
            my_putstr_error("my_hunter: invalid option(s): ");
            my_putstr_error("the 'my_hunter' executable must be called only ");
            my_putstr_error("without parameter or with the '-h' option\n");
            return EPITECH_ECHEC;
        }
    } else
        return game_launch();
}
