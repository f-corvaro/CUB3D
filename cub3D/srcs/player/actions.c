/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:35:03 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:12:35 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Initializes the player's direction based on the game's initial settings.
 * 
 * @param cub Pointer to the game engine state.
 */
void	init_player_direction(t_engine *cub)
{
	set_player_dir_ns(&cub->player);
	set_player_dir_ew(&cub->player);
}

/**
 * @brief Rotates the player based on direction.
 * 
 * @param cub Pointer to the game engine.
 * @param direction Rotation direction and magnitude.
 * @return 1 if rotation occurred, 0 otherwise.
 */
int	process_rotation(t_engine *cub, double direction)
{
	double	adj_speed;
	int		has_rot;

	adj_speed = PRS * direction;
	has_rot = 0;
	has_rot += rotate_view(cub, adj_speed);
	return (has_rot);
}

/**
 * Handles player movement and rotation.
 * 
 * @param cub Game state.
 * @return Movement status (1 if moved, 0 otherwise).
 */
int	process_movement(t_engine *cub)
{
	int	status;

	status = 0;
	if (cub->player.dx == -1)
		status += strafe_left(cub);
	if (cub->player.dx == 1)
		status += strafe_right(cub);
	if (cub->player.dy == -1)
		status += retreat_position(cub);
	if (cub->player.dy == 1)
		status += advance_position(cub);
	if (cub->player.rotation != 0)
		status += process_rotation(cub, cub->player.rotation);
	return (status);
}
