/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:13:25 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:27:22 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initializes the MLX library and creates a new window. 
 * 
 * @param cub A pointer to the engine context (`t_engine`) where the MLX 
 * library and window will be initialized.
 */
void	init_mlx(t_engine *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		shutdown_cub(cub, error_exit("mlx_linux", MLX_START, 1));
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!cub->win)
		shutdown_cub(cub, error_exit("mlx_linux", MLX_WIN, 1));
	return ;
}

/**
 * @brief Resets the image structure to its default, uninitialized state.
 * 
 * @param img A pointer to the image structure (`t_img`) to be reset.
 */
static void	reset_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->endian = 0;
	img->pix_bits = 0;
	img->size_line = 0;
}

/**
 * @brief Initializes an image with the specified width and height.
 * 
 * @param cub A pointer to the engine context (`t_engine`) 
 * associated with the current MLX instance.
 * @param img A pointer to the image structure (`t_img`) to be initialized.
 * @param w The width of the image to be created.
 * @param h The height of the image to be created.
 */
void	init_img(t_engine *cub, t_img *img, int w, int h)
{
	reset_img(img);
	img->img = mlx_new_image(cub->mlx, w, h);
	if (img->img == NULL)
		shutdown_cub(cub, error_exit("mlx_linux", MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->pix_bits, &img->size_line, &img->endian);
	return ;
}

/**
 * @brief Initializes an image from a texture file.
 * 
 * @param cub A pointer to the engine context (`t_engine`) associated with 
 * the current MLX instance.
 * @param img A pointer to the image structure (`t_img`) to be initialized 
 * with the texture.
 * @param path The file path to the texture to be loaded.
 */
void	init_texture_img(t_engine *cub, t_img *img, char *path)
{
	reset_img(img);
	img->img = mlx_xpm_file_to_image(cub->mlx,
			path, &cub->t.size, &cub->t.size);
	if (img->img == NULL)
		shutdown_cub(cub, error_exit("mlx_linux", MLX_IMG, 1));
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->pix_bits, &img->size_line, &img->endian);
	return ;
}
