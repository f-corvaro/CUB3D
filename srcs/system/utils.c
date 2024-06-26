/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:01:48 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/26 22:36:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Terminates the game and outputs an error message.
 * 
 * 
 * @param msg The error message to be displayed on termination.
 * @param cub Pointer to the game engine's main structure for accessing game 
 * resources during cleanup.
 */
void	terminate(char *msg, t_engine *cub)
{
	ft_putstr_fd(ft_strjoin(msg, "\n"), STDERR_FILENO);
	/*function to clean and terminate the game*/
}
