/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:43:06 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Converts RGB color values to a hexadecimal color.
 * 
 * This function takes an array of three integers representing the red, green, 
 * and blue components of a color, each in the range 0-255, and combines them 
 * into a single unsigned long value representing the hexadecimal color.
 * The resulting hexadecimal color is in the format 0xRRGGBB.
 * 
 * @param rgb An array of three integers representing the red, green, and blue
 * components of the color.
 * @return The hexadecimal representation of the color as an unsigned long.
 */
static unsigned long	rgb_to_hex(int *rgb)
{
	int				red;
	int				green;
	int				blue;
	unsigned long	hcolor;

	red = rgb[0];
	green = rgb[1];
	blue = rgb[2];
	hcolor = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	return (hcolor);
}

/**
 * @brief Prints an error message to standard error and returns a specified 
 * exit code.
 * 
 * @param t_err The specific error code to be included in the error message.
 * @param a_info Additional information or context about the error.
 * @param exit_code The exit code to be returned by the function.
 * @return Returns the specified exit code.
 */
static int	ierror_exit(int t_err, char *a_info, int exit_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putnbr_fd(t_err, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(a_info, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (exit_code);
}

/**
 * @brief Validates if the given RGB values are within the valid range.
 * 
 * @param rgb An array of three integers representing the RGB values to be 
 * validated.
 * @return Returns 0 if all RGB values are within the valid range, otherwise 
 * returns an error code.
 */
static int	is_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ierror_exit(rgb[i], ERR_RGB, 1));
		i++;
	}
	return (0);
}

/**
 * @brief Validates if the given path points to a valid texture file.
 * 
 * @param path The file path of the texture to be validated.
 * @return Returns 0 if the texture file is valid, otherwise returns an 
 * error code.
 */
static int	is_a_valid_texture(char *path)
{
	if (is_a_dir(path))
		return (error_exit(path, INVALID_XPM_1, 1));
	if (!is_xpm_file(path))
		return (error_exit(path, INVALID_XPM_2, 1));
	return (0);
}

/**
 * @brief Validates texture paths and RGB values for floor and ceiling colors.
 * 
 * This function performs a series of validations on the texture paths and RGB 
 * values for floor and ceiling colors specified in the `t_texture` structure. 
 * It checks if the texture paths for the north, south, west, and east walls
 * are valid and not directories. It also validates that the RGB values for 
 * floor and ceiling are within the valid range (0-255).
 * If any of the validations fail, an appropriate error message is displayed, 
 * and the function returns an error code.
 * 
 * @param cub Pointer to the `t_engine` structure containing map information 
 * used in error messages.
 * @param t Pointer to the `t_texture` structure containing the texture paths 
 * and RGB values to be validated.
 * @return Returns 0 if all validations pass, or 1 if any validation fails.
 */
int	texture_validation(t_engine *cub, t_texture *t)
{
	if (!t->north || !t->south || !t->west || !t->east)
		return (error_exit(cub->m_data.path, ERR_TEX_FORMAT_1, 1));
	if (!t->floor || !t->ceiling)
		return (error_exit(cub->m_data.path, ERR_TEX_FORMAT_2, 1));
	if (is_a_valid_texture(t->north) == 1 || is_valid_rgb(t->floor) == 1
		|| is_a_valid_texture(t->west) == 1 || is_valid_rgb(t->ceiling) == 1
		|| is_a_valid_texture(t->south) == 1
		|| is_a_valid_texture(t->east) == 1)
		return (1);
	t->hex_f = rgb_to_hex(t->floor);
	t->hex_c = rgb_to_hex(t->ceiling);
	return (0);
}
