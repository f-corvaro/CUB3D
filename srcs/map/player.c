/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:47:49 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if player's start position is valid.
 * 
 * Validates player's start position by ensuring it's not adjacent to 
 * whitespace. Checks positions around the player's start for whitespace.
 * 
 * @param cub Game engine state.
 * @param mm Map matrix.
 * @return true if valid, false otherwise.
 */
static bool	is_start_position_valid(t_engine *cub, char **mm)
{
	int	m;
	int	n;

	m = (int)cub->player.y0;
	n = (int)cub->player.x0;
	if (ft_strlen(mm[m - 1]) < (size_t)n
		|| ft_strlen(mm[m + 1]) < (size_t)n
		|| is_a_white_space(mm[m][n - 1]) == 0
		|| is_a_white_space(mm[m][n + 1]) == 0
		|| is_a_white_space(mm[m - 1][n]) == 0
		|| is_a_white_space(mm[m + 1][n]) == 0)
		return (false);
	return (true);
}

/**
 * @brief Sets and validates player's position.
 * 
 * Finds player's start in map, sets position, and validates it. 
 * Replaces start position with '0' to mark as visited.
 * 
 * @param cub Game engine state.
 * @param mm Map matrix.
 * @return 0 on success, 1 on error.
 */
int	set_n_validate_pp(t_engine *cub, char **mm)
{
	int	m;
	int	n;

	if (cub->player.u_v == '0')
		return (error_exit(cub->m_data.path, ERR_SPAWN_2, 1));
	m = 0;
	while (mm[m])
	{
		n = 0;
		while (mm[m][n])
		{
			if (ft_strchr(P_DIR, mm[m][n]))
			{
				cub->player.x0 = (double)n + 0.5;
				cub->player.y0 = (double)m + 0.5;
				mm[m][n] = '0';
			}
			n++;
		}
		m++;
	}
	if (!is_start_position_valid(cub, mm))
		return (error_exit(cub->m_data.path, ERR_SPAWN_3, 1));
	return (0);
}
