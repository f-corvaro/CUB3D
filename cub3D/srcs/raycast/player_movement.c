/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:50:52 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:13:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Advances the player's position forward.
 * @param cub Game engine state.
 * @return Success of the move.
 */
int	advance_position(t_engine *cub)
{
	double	x;
	double	y;

	x = cub->player.x0 + cub->player.dir_x * PMS;
	y = cub->player.y0 + cub->player.dir_y * PMS;
	return (move_check(cub, x, y));
}

/**
 * Moves the player's position backward.
 * @param cub Game engine state.
 * @return Success of the move.
 */
int	retreat_position(t_engine *cub)
{
	double	x;
	double	y;

	x = cub->player.x0 - cub->player.dir_x * PMS;
	y = cub->player.y0 - cub->player.dir_y * PMS;
	return (move_check(cub, x, y));
}

/**
 * Strafes the player to the left.
 * @param cub Game engine state.
 * @return Success of the move.
 */
int	strafe_left(t_engine *cub)
{
	double	x;
	double	y;

	x = cub->player.x0 + cub->player.dir_y * PMS;
	y = cub->player.y0 - cub->player.dir_x * PMS;
	return (move_check(cub, x, y));
}

/**
 * Strafes the player to the right.
 * @param cub Game engine state.
 * @return Success of the move.
 */
int	strafe_right(t_engine *cub)
{
	double	x;
	double	y;

	x = cub->player.x0 - cub->player.dir_y * PMS;
	y = cub->player.y0 + cub->player.dir_x * PMS;
	return (move_check(cub, x, y));
}

/**
 * @brief Rotates the player's view.
 * 
 * Applies a rotation matrix to the player's direction and plane based on the 
 * given speed.
 * 
 * @param cub Game engine with player info.
 * @param speed Rotation speed; positive for right, negative for left.
 * @return 1 to indicate success.
 */
int	rotate_view(t_engine *cub, double speed)
{
	t_player	*p;
	double		x;

	p = &cub->player;
	x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = x * sin(speed) + p->dir_y * cos(speed);
	x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
	p->plane_y = x * sin(speed) + p->plane_y * cos(speed);
	return (1);
}
