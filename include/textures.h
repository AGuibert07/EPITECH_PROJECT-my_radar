/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this header file countains all textures tools
*/

#ifndef TEXTURES_
    #define TEXTURES_

    #include <SFML/Graphics.h>
    #include "my.h"
    #include "sprites_structs.h"

struct texture {
    char *file_name;
    unsigned int file_width;
    unsigned int file_height;
    sfTexture *sf_texture;
} typedef texture_t;

struct element_textures {
    int version_id;
    unsigned int versions_nbr;
    texture_t *textures;
} typedef element_textures_t;

struct textures_versions {
    element_textures_t *plane_textures;
    element_textures_t *crash_textures;
    element_textures_t *tower_textures;
    element_textures_t *bg_textures;
} typedef textures_versions_t;


// functions from the get_textures_and_sprites.c source file
void update_background_texture(sfSprite *background,
    textures_versions_t *textures);
sfSprite *get_background(textures_versions_t *textures);
void update_plane_texture(aircraft_t **planes, textures_versions_t *textures);
void update_tower_texture(tower_t **towers, textures_versions_t *textures);
bool_t set_textures_and_pos(aircraft_t **planes, tower_t **towers,
    textures_versions_t *textures);
// bool_t set_textures_and_pos(aircraft_t **planes, tower_t **towers);

//functions from the textures_tools.c source file
void textures_versions_destroy(textures_versions_t *textures);
textures_versions_t *get_textures(void);

#endif /* TEXTURES_ */
