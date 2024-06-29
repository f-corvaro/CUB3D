/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:52:22 by fursini           #+#    #+#             */
/*   Updated: 2024/06/29 15:20:15 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Free all allocated memory and exit the program
 *
 * @param cube Struct with game data
 */
void	close_game(t_cube *cube)
{
	if (!cube)
		exit(0);
	if (cube->fd > 0)
		close(cube->fd);
	free_matrix(&cube->map);
	// safe_free((void **)&cube->map);
	free_matrix(&cube->elements);
	free_textures(cube);
	mlx_destroy_display(cube->mlx);
	safe_free((void **)&cube->mlx);
	exit(0);
}

