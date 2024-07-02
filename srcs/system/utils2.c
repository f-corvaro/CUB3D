/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:23:29 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 15:31:36 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Sets the color of a specific pixel in an image.
 * 
 * This function calculates the position of the pixel based on its x and
 * y coordinates, then sets the pixel's color in the image's pixel buffer. 
 * The image is represented by a t_img structure, which contains the pixel 
 * buffer (addr) and the size of each line in the buffer (size_line). 
 * The color is applied directly to the calculated pixel position within 
 * the buffer.
 * 
 * @param img Pointer to the t_img structure representing the image.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color to set the pixel to.
 */
void	set_pixel_color(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = x + ((img->size_line / 4) * y);
	img->addr[pixel] = color;
}

/**
 * @brief Checks if the given file path points to an XPM file.
 * 
 * @param path The file path to be checked.
 * @return Returns true if the file is an XPM file, false otherwise.
 */
bool	is_xpm_file(char *path)
{
	const char	*is_xpm_file;

	is_xpm_file = ft_strrchr(path, '.');
	if (is_xpm_file == NULL || (ft_strcmp(is_xpm_file, ".xpm")) != 0)
		return (false);
	return (true);
}

/**
 * @brief Converts the given string matrix to an integer RGB matrix.
 * 
 * @param sm The string matrix to be converted.
 * @param rgb The integer RGB matrix to be filled.
 * @return Returns the integer RGB matrix if the conversion was successful,
 * otherwise returns 0.
 */
static int	*str_to_rgb(char **sm, int *rgb)
{
	int		i;

	i = -1;
	while (sm[++i])
	{
		rgb[i] = ft_atoi(sm[i]);
		if (rgb[i] == -1 || contains_digit(sm[i]) == false)
		{
			free(rgb);
			free_matrix((void **)sm);
			return (0);
		}
	}
	free_matrix((void **)sm);
	return (rgb);
}

/**
 * @brief Parses a comma-separated RGB string into an array of integers.
 * 
 * @param line The input string containing comma-separated RGB values.
 * @return A pointer to an array of three integers representing the RGB 
 * values on success, or NULL on failure.
 */
int	*parse_rgb(char *line)
{
	int		i;
	int		*rgb;
	char	**sm;

	i = 0;
	sm = ft_split(line, ',');
	while (sm[i])
		i++;
	if (i != 3)
	{
		free_matrix((void **)sm);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		error_exit(NULL, ERR_MEM_A, 0);
		return (0);
	}
	return (str_to_rgb(sm, rgb));
}
