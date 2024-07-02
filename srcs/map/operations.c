/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:05:40 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 15:27:28 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Converts spaces within map lines to walls ('1'), except for trailing
 * spaces.
 * 
 * This is used to ensure that the playable area is enclosed,
 * preventing the player from moving outside the map boundaries.
 * 
 * @param cub Pointer to the game engine state, which includes the map data.
 */
void	convert_siw(t_engine *cub)
{
	int	m;
	int	n;

	m = 0;
	while (cub->map[m])
	{
		n = 0;
		while (cub->map[m][n] == '\f' || cub->map[m][n] == '\t'
		|| cub->map[m][n] == '\r' || cub->map[m][n] == '\v'
		|| cub->map[m][n] == ' ')
			n++;
		while (cub->map[m][++n])
		{
			if (cub->map[m][n] == ' '
				&& n != cub->map[m][ft_strlen(cub->map[m]) - 1])
				cub->map[m][n] = '1';
		}
		m++;
	}
}
