/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:51:52 by fursini           #+#    #+#             */
/*   Updated: 2024/06/29 12:51:37 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Get the map data from the file
 *
 * @param cube Struct with game data
 * @param map_path Path to the map file
 */

void	get_map_data(t_cube *cube, char *map_path)
{
	cube->fd = open(map_path, O_RDONLY);
	get_map_elements(cube);
	// get_map(&cube);
	// for (int i = 0; cube->map[i]; i++)
	// 	printf("%s\n", cube->map[i]);
}

void	get_map(t_cube **cube)
{
	char	*line;
	char	*trim;

	while (1)
	{
		line = get_next_line((*cube)->fd);
		if (!line)
			break ;
		trim = ft_strtrim(line, "\n");
		if (ft_strlen(trim) == 0)
		{
			safe_free((void **)&line);
			safe_free((void **)&trim);
			continue ;
		}
		(*cube)->map = ft_realloc_matrix((*cube)->map, trim);
		safe_free((void **)&line);
		safe_free((void **)&trim);
	}
}
