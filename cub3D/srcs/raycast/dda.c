/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:15:41 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Executes the Digital Differential Analyzer (DDA) algorithm for 
 * ray-wall collision detection.
 * 
 * This function iteratively advances a ray until it hits a wall or exits the 
 * map boundaries. It updates the ray's position in the map grid by 
 * incrementally adding step values based on the ray's direction. The
 * function determines whether a wall collision has occurred or if the ray has 
 * left the map area.
 * 
 * @param cub Pointer to the engine structure, containing map information and 
 * other game state.
 * @param r Pointer to the raycasting structure, containing the current state 
 * of the ray being processed.
 */
void	execute_dda(t_engine *cub, t_raycast *r)
{
	int	wcd;

	wcd = 0;
	while (wcd == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->hit_side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->hit_side = 1;
		}
		if (r->map_y < 0.25
			|| r->map_x < 0.25
			|| r->map_y > cub->m_data.height - 0.25
			|| r->map_x > cub->m_data.width - 1.25)
			break ;
		else if (cub->map[r->map_y][r->map_x] > '0')
			wcd = 1;
	}
}
