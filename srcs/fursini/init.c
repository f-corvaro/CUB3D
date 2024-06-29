/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:55:49 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 15:26:25 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initialize the game struct and start the game
 *
 * @param cube Struct with game data
 * @param map_path Path to the map file
 */

void	init_cube(t_cube *cube, char *map_path)
{
	cube->mlx = mlx_init();
	init_cube_values(cube);
	get_map_data(cube, map_path);
	close_game(cube);
}

/**
 * @brief Initialize the game struct values
 *
 * @param cube Struct with game data
 */

void	init_cube_values(t_cube *cube)
{
	cube->map = NULL;
	cube->elements = NULL;
	cube->fd = 0;
	init_textures(cube);
}

/**
 * @brief Initialize the textures
 *
 * @param cube Struct with game data
 */

void	init_textures(t_cube *cube)
{
	cube->texture[0].img = NULL;
	cube->texture[1].img = NULL;
	cube->texture[2].img = NULL;
	cube->texture[3].img = NULL;
	cube->texture[0].addr = NULL;
	cube->texture[1].addr = NULL;
	cube->texture[2].addr = NULL;
	cube->texture[3].addr = NULL;
	cube->texture[0].free = false;
	cube->texture[1].free = false;
	cube->texture[2].free = false;
	cube->texture[3].free = false;
}