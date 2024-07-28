/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:13:32 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/30 16:15:04 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @file error_handling.c
 * @brief Exits the program with a custom error message and exit code.
 *
 * @param t_err The type error message to be displayed. 
 * @param a_info Additional information to be appended to the error message. 
 * @param exit_code The exit code with which the program should terminate.
 * @return The provided exit code.
 */
int	error_exit(char *t_err, char *a_info, int exit_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (t_err)
	{
		ft_putstr_fd(t_err, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (a_info)
		ft_putstr_fd(a_info, STDERR_FILENO);
	ft_putstr_fd("\n", 2);
	return (exit_code);
}
