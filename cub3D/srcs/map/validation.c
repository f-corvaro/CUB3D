/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:05:20 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Validates map characters.
 * 
 * Iterates through map matrix, checking each character against valid elements 
 * and player directions. Marks player's initial direction if found and ensures
 * no invalid characters or multiple player starts.
 * 
 * @param cub Pointer to game engine structure.
 * @param mm Map matrix.
 * @return 0 on success, 1 on error.
 */
static int	validate_map_char(t_engine *cub, char **mm)
{
	int	m;
	int	n;

	m = 0;
	cub->player.u_v = '0';
	while (mm[m] != NULL)
	{
		n = 0;
		while (mm[m][n])
		{
			while (cub->map[m][n] == '\f' || cub->map[m][n] == '\t'
			|| cub->map[m][n] == '\r' || cub->map[m][n] == '\v'
			|| cub->map[m][n] == ' ')
				n++;
			if (!(ft_strchr(M_ELEM, mm[m][n])))
				return (error_exit(cub->m_data.path, ERR_INV_MAP_1, 1));
			if (ft_strchr(P_DIR, mm[m][n]) && cub->player.u_v != '0')
				return (error_exit(cub->m_data.path, ERR_SPAWN_1, 1));
			if (ft_strchr(P_DIR, mm[m][n]) && cub->player.u_v == '0')
				cub->player.u_v = mm[m][n];
			n++;
		}
		m++;
	}
	return (0);
}

/**
 * @brief Validates overall map data.
 * 
 * Checks for map existence, validates walls, ensures minimum height, 
 * validates characters, sets and validates player
 * position, and checks map data positioning.
 * 
 * @param cub Pointer to game engine structure.
 * @param mm Map matrix.
 * @return 0 on success, 1 on error.
 */
int	validate_map_data(t_engine *cub, char **mm)
{
	if (!cub->map)
		return (error_exit(cub->m_data.path, ERR_MAP_1, 1));
	if (validate_map_wall(&cub->m_data, mm) == 1)
		return (error_exit(cub->m_data.path, ERR_MAP_2, 1));
	if (cub->m_data.height < 3)
		return (error_exit(cub->m_data.path, ERR_MAP_3, 1));
	if (validate_map_char(cub, mm) == 1)
		return (1);
	if (set_n_validate_pp(cub, mm) == 1)
		return (1);
	if (check_map_is_at_the_end(&cub->m_data) == 1)
		return (error_exit(cub->m_data.path, ERR_MAP_4, 1));
	return (0);
}
