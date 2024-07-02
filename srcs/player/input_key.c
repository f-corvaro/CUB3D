/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:57:32 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:12:35 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Handles key press events for the game engine.
 * 
 * This function updates the player's movement and rotation based on the key 
 * pressed. It supports moving up, down, left, right, and rotating left and 
 * right. Exiting the game is also handled here if the exit action key is 
 * pressed.
 * 
 * @param key The keycode of the pressed key.
 * @param cub Pointer to the game engine structure.
 * @return Always returns 0.
 */
static int	handle_key_press(int key, t_engine *cub)
{
	if (key == ACTION_EXIT)
		close_game(cub);
	if (key == MOVE_UP)
		cub->player.dy = 1;
	if (key == MOVE_DOWN)
		cub->player.dy = -1;
	if (key == MOVE_RIGHT)
		cub->player.dx = 1;
	if (key == MOVE_LEFT)
		cub->player.dx = -1;
	if (key == RIGHT_ARROW)
		cub->player.rotation += 1;
	if (key == LEFT_ARROW)
		cub->player.rotation -= 1;
	return (0);
}

/**
 * @brief Handles key release events for the game engine.
 * 
 * @param key The keycode of the released key.
 * @param cub Pointer to the game engine structure.
 * @return Always returns 0.
 */
static int	handle_key_release(int key, t_engine *cub)
{
	if (key == ACTION_EXIT)
		close_game(cub);
	if (key == MOVE_UP && cub->player.dy == 1)
		cub->player.dy = 0;
	if (key == MOVE_DOWN && cub->player.dy == -1)
		cub->player.dy = 0;
	if (key == MOVE_RIGHT && cub->player.dx == 1)
		cub->player.dx -= 1;
	if (key == MOVE_LEFT && cub->player.dx == -1)
		cub->player.dx += 1;
	if (key == RIGHT_ARROW && cub->player.rotation >= -1)
		cub->player.rotation = 0;
	if (key == LEFT_ARROW && cub->player.rotation <= 1)
		cub->player.rotation = 0;
	return (0);
}

/**
 * @brief Sets up the input handling for the game engine.
 * 
 * This function hooks the key press and key release events to their 
 * respective handlers. It also ensures that the game can be closed 
 * properly through a client message.
 * 
 * @param cub Pointer to the game engine structure.
 */
void	input_handle(t_engine *cub)
{
	mlx_hook(cub->win, ClientMessage, NoEventMask, close_game, cub);
	mlx_hook(cub->win, KeyPress, KeyPressMask, handle_key_press, cub);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, handle_key_release, cub);
}
