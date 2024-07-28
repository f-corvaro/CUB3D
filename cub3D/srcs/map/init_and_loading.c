/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:04:46 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Allocates memory for and loads the map from file data into a 
 * 2D array.
 * 
 * This function allocates memory for each line of the map based on the 
 * maximum line length to ensure uniformity. It then copies each line from the 
 * file data into the allocated memory, padding the end of shorter lines with 
 * null characters to match the maximum width.
 * 
 * @param map Pointer to the map data structure containing map dimensions and 
 * file data.
 * @param mm Double pointer to the 2D array where the map will be loaded.
 * @param i The starting line index in the file data to begin loading the map.
 * @return Returns 0 on success, or a non-zero error code on failure.
 */
static int	alloc_n_load_map(t_map_data *map, char **mm, int i)
{
	int		m;
	int		n;

	map->width = get_max_line_len(map, i);
	m = 0;
	while (m < map->height)
	{
		n = 0;
		mm[m] = malloc(sizeof(char) * (map->width + 1));
		if (!mm[m])
			return (error_exit(NULL, ERR_MEM_A, 1));
		while (map->file[i][n] && map->file[i][n] != '\n')
		{
			mm[m][n] = map->file[i][n];
			n++;
		}
		while (n < map->width)
			mm[m][n++] = '\0';
		m++;
		i++;
	}
	mm[m] = NULL;
	return (0);
}

/**
 * @brief Counts the number of valid map lines starting from a given index.
 * 
 * Iterates through the map matrix (mm) starting from index 'm' and counts the 
 * number of consecutive lines that start with '1', indicating valid map lines. 
 * It also updates the engine's map information with the index where valid 
 * map lines end.
 * 
 * @param cub Pointer to the game engine state, which includes map information.
 * @param mm Double pointer to the 2D array representing the map.
 * @param m The starting index in the map matrix to begin counting valid lines.
 * @return The number of consecutive valid map lines.
 */
static int	count_valid_line(t_engine *cub, char **mm, int m)
{
	int	n;
	int	i;

	i = m;
	while (mm[m])
	{
		n = 0;
		while (mm[m][n] == '\f' || mm[m][n] == '\t' || mm[m][n] == '\r'
		|| mm[m][n] == '\v' || mm[m][n] == ' ')
			n++;
		if (mm[m][n] != '1')
			break ;
		m++;
	}
	cub->m_data.eom = m;
	return (m - i);
}

/**
 * @brief Initializes map data by counting valid lines and allocating memory 
 * for the map.
 * 
 * @param cub Pointer to the game engine state, which includes map information.
 * @param mm Double pointer to the 2D array representing the map before 
 * initialization.
 * @param i The starting line index in the map matrix to begin initialization.
 * @return Returns 0 on success, or 1 on failure.
 */

static int	init_map_data(t_engine *cub, char **mm, int i)
{
	cub->m_data.height = count_valid_line(cub, mm, i);
	cub->map = malloc(sizeof(char *) * (cub->m_data.height + 1));
	if (!cub->map)
		return (error_exit(NULL, ERR_MEM_A, 1));
	if (alloc_n_load_map(&cub->m_data, cub->map, i) == 1)
		return (1);
	return (0);
}

/**
 * @brief Sets up the map matrix (mm) by initializing map data and converting 
 * spaces to walls.
 * 
 * @param cub Pointer to the game engine state, which includes map information 
 * and functions.
 * @param mm Double pointer to the 2D array representing the map before setup.
 * @param i The starting line index in the map matrix to begin setup.
 * @return Returns 0 on success, or 1 on failure.
 */
int	setup_mm(t_engine *cub, char **mm, int i)
{
	if (init_map_data(cub, mm, i) == 1)
		return (1);
	convert_siw(cub);
	return (0);
}
