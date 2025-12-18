/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all textures tools functions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "assets_data.h"
#include "display_values.h"
#include "textures.h"

static void element_textures_destroy(element_textures_t *elt_textures)
{
    if (elt_textures->textures == NULL) {
        free(elt_textures);
        return;
    }
    for (int i = 0; i < elt_textures->versions_nbr; ++i) {
        if (elt_textures->textures[i].sf_texture != NULL)
            sfTexture_destroy(elt_textures->textures[i].sf_texture);
    }
    free(elt_textures);
}

void textures_versions_destroy(textures_versions_t *textures)
{
    if (textures->plane_textures != NULL)
        element_textures_destroy(textures->plane_textures);
    if (textures->tower_textures != NULL)
        element_textures_destroy(textures->tower_textures);
    if (textures->bg_textures != NULL)
        element_textures_destroy(textures->bg_textures);
    if (textures->crash_textures != NULL)
        element_textures_destroy(textures->crash_textures);
    free(textures);
}

static texture_t *get_textures_list(const int nbr, char **file_names,
    const int **sizes)
{
    texture_t *textures = malloc(sizeof(texture_t) * nbr);

    if (textures == NULL)
        return NULL;
    for (int i = 0; i < nbr; ++i) {
        textures[i].file_name = file_names[i];
        textures[i].file_width = sizes[0][i];
        textures[i].file_height = sizes[1][i];
        textures[i].sf_texture =
            sfTexture_createFromFile(file_names[i], NULL);
        if (textures[i].sf_texture == NULL) {
            free(textures);
            return NULL;
        }
    }
    return textures;
}

static element_textures_t *get_textures_for_sprite(const int nbr, const int id,
    char **file_names, const int **sizes)
{
    element_textures_t *list = malloc(sizeof(element_textures_t));

    if (list == NULL)
        return NULL;
    list->version_id = id;
    list->versions_nbr = nbr;
    list->textures = get_textures_list(nbr, file_names, sizes);
    if (list->textures == NULL) {
        free(list);
        return NULL;
    }
    return list;
}

static element_textures_t *get_crash_textures(void)
{
    element_textures_t *list = malloc(sizeof(element_textures_t));
    sfIntRect area = {0, 0, FRAME_WIDTH, FRAME_HEIGHT};

    if (list == NULL)
        return NULL;
    list->versions_nbr = CRASH_FRAME_NBR;
    list->version_id = 0;
    list->textures = malloc(sizeof(texture_t) * CRASH_FRAME_NBR);
    if (list->textures == NULL) {
        free(list);
        return NULL;
    }
    for (int i = 0; i < CRASH_FRAME_NBR; ++i) {
        area.top = FRAMES_AREAS_COORDS[i][1];
        area.left = FRAMES_AREAS_COORDS[i][0];
        list->textures[i].sf_texture =
            sfTexture_createFromFile(CRASH_FILE_NAME, &area);
    }
    return list;
}

static bool_t is_null_element(textures_versions_t *textures)
{
    if (textures->plane_textures == NULL || textures->crash_textures == NULL)
        return TRUE;
    if (textures->tower_textures == NULL || textures->bg_textures == NULL)
        return TRUE;
    return FALSE;
}

textures_versions_t *get_textures(void)
{
    textures_versions_t *textures = malloc(sizeof(textures_versions_t));
    const int *planes_sizes[2] = {_PLANES_WIDTHS_, _PLANES_HEIGHTS_};
    const int *towers_sizes[2] = {_TOWERS_WIDTHS_, _TOWERS_HEIGHTS_};
    const int *backgrounds_sizes[2] = {(const int *)(_BACKGROUNDS_WIDTHS_),
        (const int *)(_BACKGROUNDS_HEIGHTS_)};

    if (textures == NULL)
        return NULL;
    textures->plane_textures = get_textures_for_sprite(_PLANES_NBR_, _PLANE_ID_
        - 2, (char **)(_PLANES_PATHS_), (const int **)(planes_sizes));
    textures->tower_textures = get_textures_for_sprite(_TOWERS_NBR_, _TOWER_ID_
        - 2, (char **)(_TOWERS_PATHS_), (const int **)(towers_sizes));
    textures->bg_textures = get_textures_for_sprite(_BG_NBR_, _BACKGROUND_ID_ -
        2, (char **)(_BACKGROUNDS_PATHS_), backgrounds_sizes);
    textures->crash_textures = get_crash_textures();
    if (is_null_element(textures) == TRUE) {
        textures_versions_destroy(textures);
        return NULL;
    }
    return textures;
}

void set_crash_texture(aircraft_t *plane, element_textures_t *textures)
{
    double factor = ((1.0 * CRASH_SIZE) / FRAME_WIDTH);
    sfVector2f vector = {factor, factor};

    sfSprite_setTexture(plane->sf_sprite, textures->textures[0].sf_texture,
        sfTrue);
    sfSprite_setScale(plane->sf_sprite, vector);
    plane->origin.x = -(FRAME_WIDTH * factor) / 2;
    plane->origin.y = -(FRAME_HEIGHT * factor) / 2;
    vector.x = plane->position.x + plane->origin.x;
    vector.y = plane->position.y + plane->origin.y;
    sfSprite_setPosition(plane->sf_sprite, vector);
    plane->crash_frame_index = 0;
}

void update_crash_texture(aircraft_t *plane, element_textures_t *textures)
{
    plane->crash_frame_index += 1;
    sfSprite_setTexture(plane->sf_sprite, textures->textures[
            plane->crash_frame_index].sf_texture, sfTrue);
}
