/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:03:41 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 15:23:56 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Validates the command line arguments.
 * 
 * This function checks if the correct number of command line arguments 
 * are provided and verifies that the provided file has a .cub extension. 
 * It also attempts to open the file to ensure it is accessible. If any 
 * of these checks fail, the function calls error_exit to terminate the 
 * program with an appropriate error message.
 * 
 * @param ac The count of command line arguments.
 * @param av The array of command line arguments.
 * @param cub A pointer to the t_cube structure.
 */
void	check_args(int ac, const char **av, t_cube *cub)
{
	const char	*ext;

	ext = ft_strrchr(av[1], '.');
	if (ac != 2)
		error_exit(ERROR_MSG_INVALID_ARGS, &cub);
	if (ext == NULL || (ft_strcmp(ext, ".cub")) != 0)
		error_exit(ERROR_INVALID_EXTENSION, &cub);
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd == -1)
		error_exit(ERROR_UNABLE_TO_OPEN, &cub);
	else
		close(cub->fd);
}
