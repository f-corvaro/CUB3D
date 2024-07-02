/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:12:39 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 15:27:40 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Validates the edge row of the map for proper border formatting.
 * 
 * This function checks if the specified row (top or bottom edge) of the map 
 * contains only '1's after any whitespace characters.
 * It ensures that the map's border is properly formatted by verifying that 
 * all characters in the edge row, excluding leading
 * whitespace, are '1'. This is crucial for the integrity of the map's borders.
 * 
 * @param mm The map matrix represented as a 2D array of characters.
 * @param m The row index to validate.
 * @param n The starting column index for validation, typically 0.
 * @return Returns 0 if the edge row is valid, 1 otherwise.
 */
static int	validate_map_erow(char **mm, int m, int n)
{
	if (!mm || !mm[m] || !mm[m][n])
		return (1);
	while (mm[m][n] == '\t' || mm[m][n] == '\r' || mm[m][n] == '\v'
	|| mm[m][n] == '\f' || mm[m][n] == ' ')
		n++;
	while (mm[m][n])
	{
		if (mm[m][n] != '1')
			return (1);
		n++;
	}
	return (0);
}

/**
 * @brief Validates the walls of the map to ensure they are properly enclosed.
 * 
 * This function validates the map's walls by checking the top and bottom rows 
 * and the rightmost column of each row in between. It ensures that the map is 
 * properly enclosed by walls ('1's) by using `validate_map_erow` for the top
 * and bottom rows and directly checking the last character of each middle row. 
 * This validation is essential for ensuring that the map is correctly 
 * formatted and enclosed.
 * 
 * @param map A pointer to the `t_map_data` structure containing map dimensions.
 * @param mm The map matrix represented as a 2D array of characters.
 * @return Returns 0 if all walls are valid, 1 otherwise.
 */
int	validate_map_wall(t_map_data *map, char **mm)
{
	int	m;
	int	n;

	if (validate_map_erow(mm, 0, 0) == 1)
		return (1);
	m = 1;
	while (m < (map->height - 1))
	{
		n = ft_strlen(mm[m]) - 1;
		if (mm[m][n] != '1')
			return (1);
		m++;
	}
	if (validate_map_erow(mm, m, 0) == 1)
		return (1);
	return (0);
}
