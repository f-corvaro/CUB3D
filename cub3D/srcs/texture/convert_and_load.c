/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:24:46 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/03 11:08:31 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Converts an XPM file to an image buffer.
 *
 * This function loads an XPM file specified by the path, creating a temporary
 * image structure to hold the loaded image data. It then allocates a buffer to
 * store the image pixels and copies the pixel data from the temporary image to
 * the buffer. The temporary image is destroyed after copying is complete. The
 * function returns a pointer to the allocated buffer containing the image
 * pixels.
 *
 * @param cub Pointer to the t_engine structure containing texture information.
 * @param path Path to the XPM file to be loaded.
 * @return Pointer to the allocated buffer containing the image pixels, or NULL
 * 			if an error occurs during loading or memory allocation.
 */
static int	*xpm_to_img(t_engine *cub, char *path)
{
	t_img	tmp;
	int		x;
	int		y;
	int		*buffer;

	init_texture_img(cub, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * cub->t.size * cub->t.size);
	if (!buffer)
		shutdown_cub(cub, error_exit(NULL, ERR_MEM_A, 1));
	y = 0;
	while (cub->t.size > y)
	{
		x = 0;
		while (cub->t.size > x)
		{
			buffer[y * cub->t.size + x]
				= tmp.addr[y * cub->t.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx, tmp.img);
	return (buffer);
}

/**
 * @brief Loads all textures specified in the texture information of the engine.
 *
 * Allocates memory for storing pointers to texture buffers and loads each
 * texture specified in the engine's texture information by converting the
 * corresponding XPM files into image buffers. The function stores pointers to
 * these buffers in the engine's textures array.
 *
 * @param cub Pointer to the t_engine structure where the loaded textures will
 * be stored.
 */
void	load_texture(t_engine *cub)
{
	int	fd[4];

	fd[0] = open(cub->t.east, O_RDONLY);
	fd[1] = open(cub->t.west, O_RDONLY);
	fd[2] = open(cub->t.north, O_RDONLY);
	fd[3] = open(cub->t.south, O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0)
		shutdown_cub(cub, error_exit(NULL, ERR_TEX_FORMAT_1, 1));
	cub->tex_ids = ft_calloc(5, sizeof * cub->tex_ids);
	if (!cub->tex_ids)
		shutdown_cub(cub, error_exit(NULL, ERR_MEM_A, 1));
	cub->tex_ids[EAST] = xpm_to_img(cub, cub->t.east);
	cub->tex_ids[WEST] = xpm_to_img(cub, cub->t.west);
	cub->tex_ids[NORTH] = xpm_to_img(cub, cub->t.north);
	cub->tex_ids[SOUTH] = xpm_to_img(cub, cub->t.south);
}

/**
 * @brief Updates the texture for a given vertical slice of the scene.
 *
 * This function calculates the texture mapping for a single column (x) of
 * the screen, based on the raycasting result. It determines the exact texture
 * x-coordinate (wall_x) and iterates over each pixel in the column to calculate
 * the corresponding texture y-coordinate. The function also handles texture
 * shading for north and east facing walls by adjusting the color
 * intensity. Finally, it updates the engine's texture_pixels array with the
 * calculated texture colors.
 *
 * @param cub Pointer to the engine structure (`t_engine`) containing global
 * game state.
 * @param t Pointer to the current texture structure (`t_texture`) being
 * updated.
 * @param r Pointer to the raycast structure (`t_raycast`) with details of the
 * raycast.
 * @param x The x-coordinate of the screen column being updated.
 */
void	texture_update(t_engine *cub, t_texture *t, t_raycast *r, int x)
{
	int			tc;
	int			y;

	calc_texindex(cub, r);
	t->x = (int)(r->wall_x * t->size);
	if ((r->hit_side == 0 && r->dir_x < 0)
		|| (r->hit_side == 1 && r->dir_y > 0))
		t->x = t->size - t->x - 1;
	t->step = 1.0 * t->size / r->line_height;
	t->pos = (r->draw_start - cub->win_h / 2
			+ r->line_height / 2) * t->step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		t->y = (int)t->pos & (t->size - 1);
		t->pos += t->step;
		tc = cub->tex_ids[t->index][t->size * t->y + t->x];
		if (t->index == NORTH || t->index == EAST)
			tc = (tc >> 1) & 8355711;
		if (tc > 0)
			cub->tex_data[y][x] = tc;
		y++;
	}
}
