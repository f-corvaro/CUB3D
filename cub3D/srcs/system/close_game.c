/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:45:31 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/30 17:49:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Closes the game correctly, with normal exit.
 *
 *
 * @param cub A pointer to the game engine context (`t_engine`) containing all
 * the game state and resources.
 * @return Always returns 0, indicating successful closure of the game.
 */
int	close_game(t_engine *cub)
{
	shutdown_cub(cub, 0);
	return (0);
}
