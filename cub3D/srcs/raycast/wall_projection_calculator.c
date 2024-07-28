/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection_calculator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:45:12 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:20:02 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Calculates the projection of a wall slice on the screen.
 * 
 * This function determines the distance from the player to the wall hit by 
 * the ray and uses this distance to calculate the height of the wall slice 
 * projection on the screen. It also calculates the start and end
 * points for drawing the wall slice. Additionally, it computes the exact 
 * position on the wall where the ray hits, which is used for texture mapping.
 * 
 * @param r Pointer to the raycasting structure, containing the current state 
 * of the ray.
 * @param cub Pointer to the engine structure, containing game and rendering 
 * settings.
 * @param p Pointer to the player structure, containing the player's current 
 * position.
 * 
 * @note The floor function in C is part of the math library (<math.h>). 
 * It takes a single floating-point argument and returns the largest integer 
 * value less than or equal to the argument. Essentially, it rounds down the 
 * argument to the nearest whole number. floor(3.14) would return 3.0.
 * In the context of the provided code, floor(r->wall_x) is used to find 
 * the integer part of r->wall_x, effectively discarding its fractional part.
 * This is useful for texture mapping or determining the exact position on the 
 * wall where the ray hits, by normalizing the hit position to a value between 
 * 0 and 1.
 */
void	calc_wall_projection(t_raycast *r, t_engine *cub, t_player *p)
{
	if (r->hit_side == 0)
		r->wall_dist = (r->sidedist_x - r->deltadist_x);
	else
		r->wall_dist = (r->sidedist_y - r->deltadist_y);
	r->line_height = (int)(cub->win_h / r->wall_dist);
	r->draw_start = -(r->line_height) / 2 + cub->win_h / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + cub->win_h / 2;
	if (r->draw_end >= cub->win_h)
		r->draw_end = cub->win_h - 1;
	if (r->hit_side == 0)
		r->wall_x = p->y0 + r->wall_dist * r->dir_y;
	else
		r->wall_x = p->x0 + r->wall_dist * r->dir_x;
	r->wall_x -= floor(r->wall_x);
}
