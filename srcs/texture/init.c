/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:07:37 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:26 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the texture pixels matrix.
 * 
 * Allocates or reallocates memory for the texture pixels matrix based on the
 * engine's window dimensions. Frees existing memory if necessary. Exits the
 * program on memory allocation failure.
 * 
 * @param cub Pointer to the engine structure with window dimensions and texture
 * pixels array.
 */
void	init_texpix(t_engine *cub)
{
	int	i;

	if (cub->tex_data)
		free_matrix((void **)cub->tex_data);
	cub->tex_data = ft_calloc(cub->win_h + 1,
			sizeof * cub->tex_data);
	if (!cub->tex_data)
		shutdown_cub(cub, error_exit(NULL, ERR_MEM_A, 1));
	i = 0;
	while (cub->win_h > i)
	{
		cub->tex_data[i] = ft_calloc(cub->win_w + 1,
				sizeof * cub->tex_data);
		if (!cub->tex_data[i])
			shutdown_cub(cub, error_exit(NULL, ERR_MEM_A, 1));
		i++;
	}
}

/**
 * @brief Assigns texture paths to the appropriate direction in the texture 
 * structure.
 *
 * @param t A pointer to the texture structure where the extracted paths will 
 * be assigned.
 * @param line The line of text containing the direction indicator and the path.
 * @param pos The index in the line where the direction indicator starts.
 * @return int Returns 0 if a path was successfully assigned, 1 otherwise.
 */
int	assign_t_path(t_texture *t, char *line, int pos)
{
	if (ft_isprint(line[pos + 2]) && line[pos + 2])
		return (1);
	if (line[pos] == 'N' && line[pos + 1] == 'O' && !(t->north))
		t->north = extract_path(line, pos + 2);
	else if (line[pos] == 'S' && line[pos + 1] == 'O' && !(t->south))
		t->south = extract_path(line, pos + 2);
	else if (line[pos] == 'E' && line[pos + 1] == 'A' && !(t->east))
		t->east = extract_path(line, pos + 2);
	else if (line[pos] == 'W' && line[pos + 1] == 'E' && !(t->west))
		t->west = extract_path(line, pos + 2);
	else
		return (1);
	return (0);
}
