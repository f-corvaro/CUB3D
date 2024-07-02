/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:59:07 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:26 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Frees all texture path strings in a t_texture structure.
 *
 * Iterates over texture direction fields (ceiling, floor, north, 
 * south, west, east) and frees them if they are not NULL.
 *
 * @param texture Pointer to the t_texture structure to be cleaned up.
 */
void	free_texture(t_texture *texture)
{
	if (texture->ceiling)
		free(texture->ceiling);
	if (texture->floor)
		free(texture->floor);
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	if (texture->east)
		free(texture->east);
}

/**
 * @brief Frees a null-terminated array of pointers (matrix).
 *
 * Iterates over each element, freeing individual rows, followed by the array 
 * itself. Sets the matrix pointer to NULL to prevent use-after-free errors.
 *
 * @param matrix Pointer to the first element of the array.
 */
void	free_matrix(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix)
	{
		free(matrix);
		matrix = NULL;
	}
}

/**
 * @brief Frees resources allocated for the map and its information.
 *
 * Closes the map file descriptor if open, 
 * and frees the memory allocated for the map
 * and its file representation.
 *
 * @param cub Pointer to the t_engine structure containing map resources.
 */
void	free_map(t_engine *cub)
{
	if (cub->m_data.fd > 0)
		close(cub->m_data.fd);
	if (cub->m_data.file)
		free_matrix((void **)cub->m_data.file);
	if (cub->map)
		free_matrix((void **)cub->map);
}

/**
 * @brief Frees all resources allocated for the game engine.
 *
 * Releases memory for textures, texture pixels, texture information, 
 * and map resources.
 * Always returns 1 to indicate completion.
 *
 * @param cub Pointer to the t_engine structure to be cleaned up.
 * @return Always returns 1.
 */
int	free_cub(t_engine *cub)
{
	if (cub->tex_ids)
		free_matrix((void **)cub->tex_ids);
	if (cub->tex_data)
		free_matrix((void **)cub->tex_data);
	free_texture(&cub->t);
	free_map(cub);
	return (1);
}
