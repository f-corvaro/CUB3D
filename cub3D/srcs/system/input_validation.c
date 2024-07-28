/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:25:31 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 15:33:05 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Determines if the given path points to a `.cub` file.
 *
 * @param path The path to the file to be checked.
 * @return True if the file has a `.cub` extension, false otherwise.
 */
static bool	is_cub_file(char *path)
{
	const char	*is_cub_file;

	is_cub_file = ft_strrchr(path, '.');
	if (is_cub_file == NULL || (ft_strcmp(is_cub_file, ".cub")) != 0)
		return (false);
	return (true);
}

/**
 * @brief Checks if the given path corresponds to a directory.
 *
 *
 * @param path The path to be checked.
 * @return A boolean value, true if the path is a directory.
 */
bool	is_a_dir(char *path)
{
	bool	is_a_dir;
	int		fd;

	is_a_dir = false;
	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		is_a_dir = true;
	}
	return (is_a_dir);
}

/**
 * @brief Checks if the given path is a valid map file.
 *
 * This function checks if the given path is a directory, 
 * if the file can be opened, 
 * and if the file has the correct extension for a map file. 
 *
 * @param path The path to the map file to validate.
 * @return Returns 0 if the map is valid, otherwise returns 1 and prints an
 * error message.
 */
static int	is_a_valid_map(char *path)
{
	int	fd;

	if (is_a_dir(path))
		return (error_exit(path, INVALID_MAP_1, 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_exit(path, strerror(errno), 1));
	close(fd);
	if (!is_cub_file(path))
		return (error_exit(path, INVALID_MAP_2, 1));
	return (0);
}

/**
 * @brief Checks the input path given for the map file.
 *
 * @param cub A pointer to the engine structure.
 * @param av The argument vector containing the input path at index 1.
 * @return Returns 0 after performing the check, regardless of the outcome.
 */
int	check_input_path(t_engine *cub, char **av)
{
	if (is_a_valid_map(av[1]) == 1)
		shutdown_cub(cub, 1);
	return (0);
}
