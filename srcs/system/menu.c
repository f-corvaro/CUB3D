/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:09:31 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:30:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draws the control information on the game window.
 *
 * This function displays the control information on the game window,
 * including movement keys, rotation keys, and exit instructions.
 *
 * @param cub A pointer to the t_engine structure containing the game state.
 */
void	draw_control_info(t_engine *cub)
{
	void	*mlx;
	void	*win;
	int		vp;

	mlx = cub->mlx;
	win = cub->win;
	vp = START_Y;
	mlx_string_put(mlx, win, START_X, vp += LINE_SPACING, YELLOW, MENU_T);
	mlx_string_put(mlx, win, START_X, vp += LINE_SPACING, WHITE, CLOSE);
	mlx_string_put(mlx, win, START_X, vp += LINE_SPACING, WHITE, ROTATE);
	mlx_string_put(mlx, win, START_X, vp += LINE_SPACING, WHITE, MOVE);
}
