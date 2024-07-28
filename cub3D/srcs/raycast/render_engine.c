/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:01:07 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:27:22 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Executes the raycasting algorithm for each column of the screen.
 * 
 * This function iterates over each column of the screen, initializes the ray 
 * state, performs DDA for wall detection, calculates wall projection, and 
 * updates texture pixels based on the raycast results.
 * 
 * @param p Pointer to the player structure, containing the player's position 
 * and view direction.
 * @param cub Pointer to the engine structure, containing game state and 
 * rendering information.
 * @return Always returns 0.
 */
static int	exe_raycast(t_player *p, t_engine *cub)
{
	int			x;
	t_raycast	r;

	x = 0;
	r = cub->result;
	while (cub->win_w > x)
	{
		init_ray_state(x, &r, p);
		init_dda(&r, p);
		execute_dda(cub, &r);
		calc_wall_projection(&r, cub, p);
		texture_update(cub, &cub->t, &r, x);
		x++;
	}
	return (0);
}

/**
 * @brief Executes the raycasting and rendering process.
 * 
 * Initializes texture pixels and the raycasting state, 
 * executes the raycasting algorithm,
 * and then renders the frame based on the raycasting results.
 * 
 * @param cub Pointer to the engine structure, containing game state and 
 * rendering information.
 */
void	exe_raynren(t_engine *cub)
{
	init_texpix(cub);
	init_raycast(&cub->result);
	exe_raycast(&cub->player, cub);
	render_scene(cub);
}

/**
 * @brief Updates and renders the frame if the player has moved.
 * 
 * Processes player movement and checks if the player has moved. If the 
 * player has moved, executes the raycasting and rendering process.
 * 
 * @param cub Pointer to the engine structure, containing game state and 
 * rendering information.
 * @return Always returns 0. Returns early if the player has not moved.
 */
int	upnren_frame(t_engine *cub)
{
	cub->player.has_moved += process_movement(cub);
	if (cub->player.has_moved == 0)
		return (0);
	exe_raynren(cub);
	return (0);
}
