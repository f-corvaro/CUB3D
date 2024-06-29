/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:09:23 by fursini           #+#    #+#             */
/*   Updated: 2024/06/29 12:50:59 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Free a pointer and set it to NULL
 *
 * @param ptr Pointer to free
 */

void	safe_free(void **ptr)
{
	if (ptr && *ptr)
		free(*ptr);
	*ptr = NULL;
}

/**
 * @brief Free a matrix of strings
 *
 * @param matrix Matrix to free
 */

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	if (matrix && *matrix)
	{
		while ((*matrix)[i])
		{
			safe_free((void **)&((*matrix)[i]));
			i++;
		}
		safe_free((void **)matrix);
	}
}

/**
 * @brief Free all textures
 *
 * @param cube Struct with game data
 */

void	free_textures(t_cube *cube)
{
	if (cube->texture[0].free == true)
		mlx_destroy_image(cube->mlx, cube->texture[0].img);
	if (cube->texture[1].free == true)
		mlx_destroy_image(cube->mlx, cube->texture[1].img);
	if (cube->texture[2].free == true)
		mlx_destroy_image(cube->mlx, cube->texture[2].img);
	if (cube->texture[3].free == true)
		mlx_destroy_image(cube->mlx, cube->texture[3].img);
}

