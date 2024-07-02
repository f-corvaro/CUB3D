/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:00:19 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:13:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Updates the player's position if the new coordinates are valid.
 * 
 * This function attempts to move the player to new x and y coordinates,
 * provided they are within valid areas of the game map. The player's position 
 * is updated only if the new position does not violate map boundaries or game 
 * rules.
 * 
 * @param cub Pointer to the game engine state.
 * @param x1 Proposed new x-coordinate for the player.
 * @param y1 Proposed new y-coordinate for the player.
 * @return 1 if the player's position was updated, 0 otherwise.
 */
int	move_check(t_engine *cub, double x1, double y1)
{
	int	u_p;

	u_p = 0;
	if (is_valid_pos(cub, x1, cub->player.y0))
	{
		cub->player.x0 = x1;
		u_p = 1;
	}
	if (is_valid_pos(cub, cub->player.x0, y1))
	{
		cub->player.y0 = y1;
		u_p = 1;
	}
	return (u_p);
}
