/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:06:22 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:20:02 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the raycasting state with default values.
 * 
 * This function sets all fields of the t_raycast structure to their 
 * initial values, effectively resetting the raycasting state for a new frame 
 * or calculation.
 * 
 * @param state Pointer to the t_raycast structure to be initialized.
 */
void	init_raycast(t_raycast *state)
{
	state->draw_start = 0;
	state->draw_end = 0;
	state->map_x = 0;
	state->map_y = 0;
	state->dir_x = 0;
	state->dir_y = 0;
	state->step_x = 0;
	state->step_y = 0;
	state->sidedist_x = 0;
	state->sidedist_y = 0;
	state->deltadist_x = 0;
	state->deltadist_y = 0;
	state->camera_x = 0;
	state->wall_x = 0;
	state->wall_dist = 0;
	state->hit_side = 0;
	state->line_height = 0;
}

/**
 * @brief Initializes the state of a ray for raycasting.
 * 
 * This function sets up the initial state of a ray that is to be cast, 
 * calculating its position, direction, and the distances it needs to 
 * travel in the x and y directions to hit a wall.
 * 
 * @param x The x-coordinate of the pixel column being processed.
 * @param r Pointer to the raycasting structure to be initialized.
 * @param p Pointer to the player structure, containing the player's 
 * position and direction.
 * 
 * @note The `fabs` function in C returns the absolute value of a 
 * floating-point number. It's used here to ensure that the delta distances 
 * are positive values, regardless of the direction of the ray. 
 * These delta distances represent how far the ray must travel in the x or y 
 * direction to cross a grid boundary in the game map, which is crucial for 
 * the raycasting algorithm to calculate intersections with walls correctly.
 */
void	init_ray_state(int x, t_raycast *r, t_player *p)
{
	init_raycast(r);
	r->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	r->dir_x = p->dir_x + p->plane_x * r->camera_x;
	r->dir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->x0;
	r->map_y = (int)p->y0;
	r->deltadist_x = fabs(1 / r->dir_x);
	r->deltadist_y = fabs(1 / r->dir_y);
}

/**
 * @brief Initializes the step and side distance variables for DDA algorithm.
 * 
 * This function prepares the raycasting process by setting up the initial step
 * values and side distances for the Digital Differential Analyzer (DDA) 
 * algorithm based on the ray's direction. These variables are essential 
 * for determining how the ray will traverse through the grid and when it 
 * will hit a wall.
 * 
 * @param r Pointer to the raycasting structure containing the ray's 
 * direction and other relevant data.
 * @param p Pointer to the player structure, containing the player's current 
 * position.
 */
void	init_dda(t_raycast *r, t_player *p)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (p->x0 - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - p->x0) * r->deltadist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (p->y0 - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - p->y0) * r->deltadist_y;
	}
}

/**
 * Initializes player direction and plane for N/S orientation.
 * @param state Player state.
 */
void	set_player_dir_ns(t_player *state)
{
	if (state->u_v == 'N')
	{
		state->dir_x = 0;
		state->dir_y = -1;
		state->plane_x = 0.66;
		state->plane_y = 0;
	}
	else if (state->u_v == 'S')
	{
		state->dir_x = 0;
		state->dir_y = 1;
		state->plane_x = -0.66;
		state->plane_y = 0;
	}
	else
		return ;
}

/**
 * Initializes player direction and plane for E/W orientation.
 * @param state Player state.
 */
void	set_player_dir_ew(t_player *state)
{
	if (state->u_v == 'E')
	{
		state->dir_x = 1;
		state->dir_y = 0;
		state->plane_x = 0;
		state->plane_y = 0.66;
	}
	else if (state->u_v == 'W')
	{
		state->dir_x = -1;
		state->dir_y = 0;
		state->plane_x = 0;
		state->plane_y = -0.66;
	}
	else
		return ;
}
