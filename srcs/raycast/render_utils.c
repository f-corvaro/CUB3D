/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:03:26 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:26 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Applies texture or color to a pixel based on its position.
 * 
 * This function checks if the pixel at the specified coordinates should have 
 * a texture applied. If the texture_pixels value is greater than 0, it applies
 * the texture color. Otherwise, it applies a ceiling color for pixels above 
 * the middle of the window, and a floor color for pixels below.
 * 
 * @param cub Pointer to the engine structure containing texture and color 
 * information.
 * @param img Pointer to the image structure where the pixel color will be set.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 */
void	apply_to_pix(t_engine *cub, t_img *img, int x, int y)
{
	if (cub->tex_data[y][x] > 0)
		set_pixel_color(img, x, y, cub->tex_data[y][x]);
	else if (y < cub->win_h / 2)
		set_pixel_color(img, x, y, cub->t.hex_c);
	else if (y < cub->win_h -1)
		set_pixel_color(img, x, y, cub->t.hex_f);
}

/**
 * @brief Renders the entire scene by applying textures and colors to 
 * each pixel.
 * 
 * This function iterates over each pixel in the window, applying textures 
 * or colors based on the pixel's position and the defined textures. After 
 * processing all pixels, the image is displayed in the window and the image 
 * memory is freed.
 * 
 * @param cub Pointer to the engine structure containing window and texture 
 * information.
 */
void	render_scene(t_engine *cub)
{
	int		x;
	int		y;
	t_img	img;

	y = 0;
	img.img = NULL;
	init_img(cub, &img, cub->win_w, cub->win_h);
	while (y < cub->win_h)
	{
		x = 0;
		while (x < cub->win_w)
		{
			apply_to_pix(cub, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, img.img, 0, 0);
	mlx_destroy_image(cub->mlx, img.img);
}

/**
 * @brief Calculates the texture index based on the raycast direction.
 * 
 * This function determines the wall's orientation that the ray has hit 
 * and assigns the appropriate texture index to the engine's texture 
 * information structure. The texture index corresponds to one of the 
 * four cardinal directions (NORTH, SOUTH, EAST, WEST), depending on the 
 * ray's direction and which side of the wall it hit.
 * 
 * @param cub Pointer to the engine structure (`t_engine`) containing global 
 * game state and texture information.
 * @param r Pointer to the raycast structure (`t_raycast`) with details of 
 * the ray's direction and the side of the wall it hit.
 */
void	calc_texindex(t_engine *cub, t_raycast *r)
{
	if (r->hit_side == 0)
	{
		if (r->dir_x < 0)
			cub->t.index = WEST;
		else
			cub->t.index = EAST;
	}
	else
	{
		if (r->dir_y > 0)
			cub->t.index = SOUTH;
		else
			cub->t.index = NORTH;
	}
}
