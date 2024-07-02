/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:51:24 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Builds a matrix from the map file.
 * 
 * Reads lines from the map file descriptor and stores them in a dynamically 
 * allocated matrix within the t_engine structure.
 * 
 * @param m The starting row index for the matrix.
 * @param n The starting column index for the matrix.
 * @param i The index used for iterating through characters in a line.
 * @param cub Pointer to the t_engine structure containing map information.
 * 
 * @note This function dynamically allocates memory for each line in the matrix 
 * and requires manual memory management to avoid leaks.
 */
void	build_map_matrix(int m, int n, int i, t_engine *cub)
{
	char	*line;

	line = get_next_line(cub->m_data.fd);
	while (line != NULL)
	{
		cub->m_data.file[m] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!cub->m_data.file[m])
		{
			error_exit(NULL, ERR_MEM_A, 0);
			return (free_matrix((void **)cub->m_data.file));
		}
		while (line[i] != '\0')
			cub->m_data.file[m][n++] = line[i++];
		cub->m_data.file[m++][n] = '\0';
		n = 0;
		i = 0;
		free(line);
		line = get_next_line(cub->m_data.fd);
	}
	cub->m_data.file[m] = NULL;
}

/**
 * @brief Counts the number of lines in a map file.
 * 
 * Opens a map file at the given path and counts the number of lines it 
 * contains. This is used to determine the size of the matrix needed to 
 * store the map.
 * 
 * @param path The file path to the map file.
 * @return The number of lines in the file, or -1 if the file cannot be 
 * opened.
 * 
 * @note This function does not handle the content of the lines, merely 
 * counts them. It's used in pre-processing to allocate the right amount 
 * of memory.
 */
int	count_map_lines(char *path)
{
	int		i;
	int		fd;
	char	*c_line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(path, strerror(errno), errno);
	else
	{
		c_line = get_next_line(fd);
		while (c_line != NULL)
		{
			i++;
			free(c_line);
			c_line = get_next_line(fd);
		}
		close(fd);
	}
	return (i);
}
