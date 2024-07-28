/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:31:09 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:26 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the player state to default values.
 * 
 * @param state Pointer to the t_player structure to be initialized.
 */
static void	init_p_state(t_player *state)
{
	state->u_v = '\0';
	state->dx = 0;
	state->dy = 0;
	state->rotation = 0;
	state->x0 = 0.0;
	state->y0 = 0.0;
	state->dir_x = 0.0;
	state->dir_y = 0.0;
	state->plane_x = 0.0;
	state->plane_y = 0.0;
	state->has_moved = 0;
}

/**
 * @brief Initializes the map data structure with default values.
 * 
 * @param data Pointer to the t_map_data structure to be initialized.
 */
static void	init_map_data(t_map_data *data)
{
	data->path = NULL;
	data->file = NULL;
	data->fd = 0;
	data->width = 0;
	data->height = 0;
	data->line_count = 0;
	data->eom = 0;
}

/**
 * @brief Initializes texture attributes to default values.
 * 
 * @param t Pointer to the t_texture structure to be initialized.
 */
static void	init_texture(t_texture *t)
{
	t->north = NULL;
	t->south = NULL;
	t->west = NULL;
	t->east = NULL;
	t->size = TEX_SIZE;
	t->x = 0;
	t->y = 0;
	t->floor = 0;
	t->ceiling = 0;
	t->pos = 0.0;
	t->step = 0.0;
	t->hex_f = 0x0;
	t->hex_c = 0x0;
}

/**
 * @brief Sets up the initial state of the engine.
 * 
 * Initializes the main components of the t_engine structure, 
 * including window parameters, player state, and map data, 
 * to their starting values.
 * 
 * @param cub Pointer to the t_engine structure to be set up.
 */
void	setup_engine(t_engine *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->map = NULL;
	cub->tex_ids = NULL;
	cub->tex_data = NULL;
	cub->win_w = WIN_WIDTH;
	cub->win_h = WIN_HEIGHT;
	init_p_state(&cub->player);
	init_texture(&cub->t);
	init_map_data(&cub->m_data);
}

/**
 * @brief Initializes the game by loading and validating map and texture data.
 * 
 * This function is responsible for initializing the game environment. It loads 
 * the map from a file, validates the map and texture data, and initializes the 
 * player's direction. If any step fails, it cleans up allocated resources and 
 * returns an error code.
 * 
 * @param cub Pointer to the engine structure to be initialized.
 * @param av Command line arguments passed to the program, where av[1] is 
 * expected to be the path to the map file.
 * @return Returns 0 on successful initialization, or a non-zero value if an 
 * error occurs during the process.
 */
int	init_game(t_engine *cub, char **av)
{
	lns_map(av[1], cub);
	if (process_map_data(cub, cub->m_data.file) == 1)
		return (free_cub(cub));
	if (validate_map_data(cub, cub->map) == 1)
		return (free_cub(cub));
	if (texture_validation(cub, &cub->t) == 1)
		return (free_cub(cub));
	init_player_direction(cub);
	return (0);
}
