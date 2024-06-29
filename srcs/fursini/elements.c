/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:53:21 by fursini           #+#    #+#             */
/*   Updated: 2024/06/29 12:50:32 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief Get the map elements from the file
 *
 * @param cube Struct with game data
 */

void	get_map_elements(t_cube *cube)
{
	char	*line;
	char	*trim;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(cube->fd);
		if (!line)
			error_exit("Missing some map element", cube);
		trim = ft_strtrim(line, "\n");
		if (ft_strlen(trim) == 0)
		{
			safe_free((void **)&line);
			safe_free((void **)&trim);
			continue ;
		}
		cube->elements = ft_split(trim, ' ');
		safe_free((void **)&line);
		safe_free((void **)&trim);
		get_line_elements(cube);
		free_matrix(&cube->elements);
		i++;
	}
}

/**
 * @brief Get the elements from one line
 *
 * @param cube Struct with game data
 */

void	get_line_elements(t_cube *cube)
{
	if (ft_matrixlen(cube->elements) != 2)
		error_exit("Wrong number of elements in one line", cube);
	if (ft_strlen(cube->elements[0]) == 2)
		get_texture(cube);
	else if (ft_strlen(cube->elements[0]) == 1)
		get_color(cube);
	else
		error_exit("Invalid texture or color identifier", cube);
}

/**
 * @brief Get the texture from the line
 *
 * @param cube Struct with game data
 */

void	get_texture(t_cube *cube)
{
	int			fd;
	static int	nswe[4];

	if (ft_strcmp(ft_strrchr(cube->elements[1], '.'), ".xpm"))
		error_exit("Invalid texture file extension", cube);
	fd = open(cube->elements[1], O_RDONLY);
	if (fd < 0)
		error_exit("Invalid texture file", cube);
	if (!ft_strcmp(cube->elements[0], "NO") && nswe[0]++ == 0)
		init_texture(cube, 0, cube->elements[1]);
	else if (!ft_strcmp(cube->elements[0], "SO") && nswe[1]++ == 0)
		init_texture(cube, 1, cube->elements[1]);
	else if (!ft_strcmp(cube->elements[0], "WE") && nswe[2]++ == 0)
		init_texture(cube, 2, cube->elements[1]);
	else if (!ft_strcmp(cube->elements[0], "EA") && nswe[3]++ == 0)
		init_texture(cube, 3, cube->elements[1]);
	else
		error_exit("Invalid texture identifier", cube);
}

/**
 * @brief Get the color from the line
 *
 * @param cube Struct with game data
 */

void	get_color(t_cube *cube)
{
	int		n[2];
	char	**colors;

	n[0] = -1;
	colors = ft_split(cube->elements[1], ',');
	if (ft_matrixlen(colors) != 3)
		error_exit("Wrong number of colors", cube);
	while (++n[0] < 3)
	{
		if (ft_strlen(colors[n[0]]) > 3 || !ft_isnumber(colors[n[0]]))
			error_exit("Invalid color", cube);
		n[1] = ft_atoi(colors[n[0]]);
		if (n[1] < 0 || n[1] > 255)
			error_exit("Invalid color range", cube);
		if (!ft_strcmp(cube->elements[0], "F"))
			cube->floor_color[n[0]] = n[1];
		else if (!ft_strcmp(cube->elements[0], "C"))
			cube->ceiling_color[n[0]] = n[1];
		else
		{
			free_matrix(&colors);
			error_exit("Invalid color identifier", cube);
		}
	}
	free_matrix(&colors);
}

/**
 * @brief Initialize the texture
 *
 * @param cube Struct with game data
 * @param dir Texture direction
 * @param path Path to the texture file
 */

void	set_texture(t_cube *cube, int dir, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("Invalid texture file", cube);
	close(fd);
	cube->texture[dir].img = mlx_xpm_file_to_image(cube->mlx, path,
			&cube->texture[dir].width, &cube->texture[dir].height);
	cube->texture[dir].addr = mlx_get_data_addr(cube->texture[dir].img,
			&cube->texture[dir].bits_per_pixel, &cube->texture[dir].line_length,
			&cube->texture[dir].endian);
	cube->texture[dir].free = true;
}
