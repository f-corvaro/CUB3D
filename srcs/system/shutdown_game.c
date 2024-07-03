/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:47:50 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/03 10:46:32 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Shuts down the game engine and exits the program with the exit_code
 * provided.
 *
 * @param cub A pointer to the game engine context (`t_engine`) containing all
 * the game state and resources.
 * @param exit_code The exit code with which the program should terminate.
 */
void	shutdown_cub(t_engine *cub, int exit_code)
{
	if (!cub)
		exit(exit_code);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		mlx_loop_end(cub->mlx);
		free(cub->mlx);
	}
	free_cub(cub);
	exit(exit_code);
}
