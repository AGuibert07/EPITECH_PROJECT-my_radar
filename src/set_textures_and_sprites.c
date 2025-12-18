/*
** EPITECH PROJECT, 2025
** G1 - C Graphical Programming - my_radar
** File description:
** this file countains all functions to get textures and backgrounds
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "display_values.h"
#include "my.h"
#include "sprites_structs.h"
#include "textures.h"

void update_background_texture(sfSprite *background,
    textures_versions_t *textures)
{
    sfVector2f vector = {1, 1};
    double bg_scale_factor = 0.0;
    texture_t t;
    int *bg_id = &textures->bg_textures->version_id;

    *bg_id = (*bg_id + 1) % textures->bg_textures->versions_nbr;
    t = textures->bg_textures->textures[*bg_id];
    if (((1.0 * t.file_width) / t.file_height) >= SCREEN_RATIO)
        bg_scale_factor = (1.0 * SCREEN_WIDTH) / t.file_width;
    else
        bg_scale_factor = (1.0 * SCREEN_HEIGHT) / t.file_height;
    vector.x = bg_scale_factor;
    vector.y = bg_scale_factor;
    sfSprite_setTexture(background, t.sf_texture, sfTrue);
    sfSprite_setScale(background, vector);
    vector.x = (SCREEN_WIDTH - (t.file_width * bg_scale_factor)) / 2.0;
    vector.y = (SCREEN_HEIGHT - (t.file_height * bg_scale_factor)) / 2.0;
    sfSprite_setPosition(background, vector);
}

sfSprite *get_background(textures_versions_t *textures)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return NULL;
    update_background_texture(sprite, textures);
    return sprite;
}

static bool_t set_planes_trajectories(aircraft_t **planes)
{
    sfColor color = sfColor_fromRGB(TRAJECTORIES_COLOR[0],
        TRAJECTORIES_COLOR[1], TRAJECTORIES_COLOR[2]);
    sfVector2f vector = {0, 0};

    for (int i = 0; planes[i] != NULL; ++i) {
        sfRectangleShape_setOutlineColor(planes[i]->trajectory, color);
        sfRectangleShape_setFillColor(planes[i]->trajectory, sfTransparent);
        sfRectangleShape_setOutlineThickness(planes[i]->trajectory,
            BOX_LINE_SIZE / 2.0);
        vector.x = planes[i]->end_pos.x - planes[i]->start_pos.x;
        vector.y = planes[i]->end_pos.y - planes[i]->start_pos.y;
        vector.x = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
        vector.y = 0;
        sfRectangleShape_setSize(planes[i]->trajectory, vector);
        sfRectangleShape_setRotation(planes[i]->trajectory,
            planes[i]->orientation);
        sfRectangleShape_setPosition(planes[i]->trajectory,
            planes[i]->start_pos);
    }
    return TRUE;
}

static bool_t set_sprites_positions(aircraft_t **planes, tower_t **towers)
{
    sfVector2f position = {0, 0};

    for (int i = 0; planes[i] != NULL; ++i) {
        position.x = PLANE_BOX_SIZE / 2.0;
        position.y = PLANE_BOX_SIZE / 2.0;
        sfRectangleShape_setOrigin(planes[i]->box, position);
        position.x = (planes[i]->position.x) + (planes[i]->origin.x);
        position.y = (planes[i]->position.y) + (planes[i]->origin.y);
        sfSprite_setPosition(planes[i]->sf_sprite, position);
        sfRectangleShape_setPosition(planes[i]->box, planes[i]->position);
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        position.x = towers[i]->position.x + towers[i]->origin.x;
        position.y = towers[i]->position.y + towers[i]->origin.y;
        sfSprite_setPosition(towers[i]->sf_sprite, position);
        position.x = towers[i]->position.x - towers[i]->area_radius;
        position.y = towers[i]->position.y - towers[i]->area_radius;
        sfCircleShape_setPosition(towers[i]->zone, position);
    }
    return set_planes_trajectories(planes);
}

static bool_t set_sprites_boxes(aircraft_t **planes, tower_t **towers)
{
    sfVector2f size = {PLANE_BOX_SIZE, PLANE_BOX_SIZE};
    sfColor plane_box_color = sfColor_fromRGB(PLANE_BOX_COLOR[0],
        PLANE_BOX_COLOR[1], PLANE_BOX_COLOR[2]);
    sfColor tower_box_color = sfColor_fromRGB(TOWER_AREA_COLOR[0],
        TOWER_AREA_COLOR[1], TOWER_AREA_COLOR[2]);

    for (int i = 0; planes[i] != NULL; ++i) {
        sfRectangleShape_setSize(planes[i]->box, size);
        sfRectangleShape_setRotation(planes[i]->box, planes[i]->orientation);
        sfRectangleShape_setOutlineColor(planes[i]->box, plane_box_color);
        sfRectangleShape_setOutlineThickness(planes[i]->box, BOX_LINE_SIZE);
        sfRectangleShape_setFillColor(planes[i]->box, sfTransparent);
    }
    for (int i = 0; towers[i] != NULL; ++i) {
        sfCircleShape_setRadius(towers[i]->zone, towers[i]->area_radius);
        sfCircleShape_setOutlineColor(towers[i]->zone, tower_box_color);
        sfCircleShape_setOutlineThickness(towers[i]->zone, BOX_LINE_SIZE);
        sfCircleShape_setFillColor(towers[i]->zone, sfTransparent);
    }
    return set_sprites_positions(planes, towers);
}

static double get_scale_factor(unsigned int size, element_textures_t *textures)
{
    double scale_factor = 0.0;
    sfVector2f scale_vector = {0, 0};
    texture_t t;
    int *p_id = &(textures->version_id);

    *p_id = (*p_id + 1) % (textures->versions_nbr);
    t = textures->textures[*p_id];
    return (1.0 * size) / t.file_width;
}

void update_plane_texture(aircraft_t **planes, textures_versions_t *textures)
{
    double scale_factor = get_scale_factor(PLANE_SIZE,
        textures->plane_textures);
    sfVector2f scale_vector = {scale_factor, scale_factor};

    for (int i = 0; planes[i] != NULL; ++i) {
        sfSprite_setTexture(planes[i]->sf_sprite, textures->plane_textures->
            textures[textures->plane_textures->version_id].sf_texture, sfTrue);
        sfSprite_setScale(planes[i]->sf_sprite, scale_vector);
    }
}

void update_tower_texture(tower_t **towers, textures_versions_t *textures)
{
    double scale_factor = get_scale_factor(TOWER_SIZE,
        textures->tower_textures);
    sfVector2f scale_vector = {scale_factor, scale_factor};

    for (int i = 0; towers[i] != NULL; ++i) {
        sfSprite_setTexture(towers[i]->sf_sprite, textures->tower_textures->
            textures[textures->tower_textures->version_id].sf_texture, sfTrue);
        sfSprite_setScale(towers[i]->sf_sprite, scale_vector);
        towers[i]->origin.y = -scale_factor * (textures->tower_textures->
            textures[textures->tower_textures->version_id].file_height);
    }
}

bool_t set_textures_and_pos(aircraft_t **planes, tower_t **towers,
    textures_versions_t *textures)
{
    update_plane_texture(planes, textures);
    for (int i = 0; planes[i] != NULL; ++i) {
        sfSprite_setRotation(planes[i]->sf_sprite, planes[i]->orientation);
    }
    update_tower_texture(towers, textures);
    return set_sprites_boxes(planes, towers);
}
