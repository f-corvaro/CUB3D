/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:06:23 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Checks if a given position is within the game map boundaries.
 * 
 * This function evaluates whether the specified coordinates (x1, y1) are within
 * the valid range of the game map's dimensions, considering a margin to prevent
 * the player from moving too close to the map's edge.
 * 
 * @param cub Pointer to the game engine state.
 * @param x1 The x-coordinate of the position to check.
 * @param y1 The y-coordinate of the position to check.
 * @return true if the position is within valid boundaries, false otherwise.
 */
bool	is_valid_pos(t_engine *cub, double x1, double y1)
{
	if (x1 < 0.25 || x1 >= cub->m_data.width - 1.25)
		return (false);
	if (y1 < 0.25 || y1 >= cub->m_data.height -0.25)
		return (false);
	return (true);
}
