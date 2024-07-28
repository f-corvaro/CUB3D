/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:51:16 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:27:22 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Loads the map from a file and stores its data in the engine structure.
 * 
 * This function counts the number of lines in the map file, allocates memory 
 * for storing these lines, and then builds the map matrix by reading the file.
 * It handles file opening and closing, and in case of memory allocation failure
 * or file opening failure, it exits the program with an appropriate error 
 * message.
 * 
 * @param path The path to the map file.
 * @param cub Pointer to the engine structure where the map data will be stored.
 */
void	lns_map(char *path, t_engine *cub)
{
	cub->m_data.line_count = count_map_lines(path);
	cub->m_data.path = path;
	cub->m_data.file = ft_calloc(cub->m_data.line_count + 1, sizeof(char *));
	if (!(cub->m_data.file))
	{
		error_exit(NULL, ERR_MEM_A, 0);
		return ;
	}
	cub->m_data.fd = open(path, O_RDONLY);
	if (cub->m_data.fd < 0)
		error_exit(path, strerror(errno), 1);
	else
	{
		build_map_matrix(0, 0, 0, cub);
		close(cub->m_data.fd);
	}
}

/**
 * @brief Processes a single line of the map data for texture paths, colors, 
 * or map matrix setup.
 *
 * @param cub Pointer to the engine structure where the map data is being 
 * stored.
 * @param mm Double pointer to the array of strings representing the map data.
 * @param m The current line index in the map data array to be processed.
 * @param n The current character index in the line, initially set to start at 
 * 0.
 * @return int Returns 99 if a texture path or color is successfully processed, 
 * 0 if the line is successfully processed as part of the map matrix, 1 on error
 * in setting floor/ceiling color, and 10 if none of the conditions are met. 
 * Specific errors in texture path assignment or map matrix setup return through
 * error_exit function.
 */
static int	process_map_line(t_engine *cub, char **mm, int m, int n)
{
	while (mm[m][n] == '\n' || mm[m][n] == '\t' || mm[m][n] == ' ')
		n++;
	if (!ft_isdigit(mm[m][n]) && ft_isprint(mm[m][n]))
	{
		if (mm[m][n + 1] && !ft_isdigit(mm[m][n]) && ft_isprint(mm[m][n + 1]))
		{
			if (assign_t_path(&cub->t, mm[m], n) == 1)
				return (error_exit(cub->m_data.path, ERR_TEX_FORMAT_1, 1));
			return (99);
		}
		else
		{
			if (set_fnc_color(cub, &cub->t, mm[m], n) == 1)
				return (1);
			return (99);
		}
	}
	else if (ft_isdigit(mm[m][n]))
	{
		if (setup_mm(cub, mm, m) == 1)
			return (error_exit(cub->m_data.path, ERR_INV_MAP_2, 1));
		return (0);
	}
	return (10);
}

/**
 * @brief Checks if the map data is followed only by whitespace or new lines 
 * in the file.
 * 
 * This function iterates through the file content starting from the end of the 
 * map data. It checks each character to ensure that only whitespace characters 
 * (space, form feed, tab, carriage return, newline, and vertical tab)
 * are present after the map data. If any non-whitespace character is found, 
 * it indicates that there is additional content after the map data, which 
 * is not allowed.
 * 
 * @param map A pointer to a `t_map_data` structure containing the map data and 
 * its position in the file.
 * @return Returns 0 if only whitespace characters are found after the map data,
 * 1 otherwise.
 */
int	check_map_is_at_the_end(t_map_data *map)
{
	int	m;
	int	n;

	m = map->eom;
	while (map->file[m])
	{
		n = 0;
		while (map->file[m][n])
		{
			if (map->file[m][n] != '\f' && map->file[m][n] != '\t'
				&& map->file[m][n] != '\r' && map->file[m][n] != '\n'
				&& map->file[m][n] != '\v' && map->file[m][n] != ' ')
				return (1);
			n++;
		}
		m++;
	}
	return (0);
}

/**
 * @brief Parses and sets the floor or ceiling color from a configuration line.
 * 
 * This function checks the given line for floor (F) or ceiling (C) identifiers
 * followed by RGB values. It parses these RGB values and sets them for the
 * floor or ceiling in the texture structure. If the line is incorrectly 
 * formatted, or if the RGB values are invalid, the function returns an error.
 * 
 * @param cub A pointer to the engine structure where the map information 
 * is stored.
 * @param t A pointer to the texture structure where the ceiling and floor 
 * colors are set.
 * @param line The configuration line to be parsed.
 * @param i The index in the line where the floor or ceiling identifier is 
 * found.
 * @return int Returns 0 on success, or an error code on failure.
 */
int	set_fnc_color(t_engine *cub, t_texture *t, char *line, int i)
{
	if (ft_isprint(line[i + 1]) && line[i + 1])
		return (error_exit(cub->m_data.path, ERR_RGB, 1));
	if (!t->floor && line[i] == 'F')
	{
		t->floor = parse_rgb(line + i + 1);
		if (t->floor == 0)
			return (error_exit(cub->m_data.path, ERR_RGB, 1));
	}
	else if (!t->ceiling && line[i] == 'C')
	{
		t->ceiling = parse_rgb(line + i + 1);
		if (t->ceiling == 0)
			return (error_exit(cub->m_data.path, ERR_RGB, 1));
	}
	else
		return (error_exit(cub->m_data.path, ERR_RGB, 1));
	return (0);
}

/**
 * @brief Processes map data to initialize the engine's map structure.
 *
 * Loops through map lines and characters, processing each with 
 * process_map_line. Exits early on specific return values indicating
 * success, error, or a break condition.
 *
 * @param cub Engine structure pointer.
 * @param mm Map data as an array of strings.
 * @return Returns 0 on success, 1 on error.
 */
int	process_map_data(t_engine *cub, char **mm)
{
	int	m;
	int	n;
	int	pr;

	m = 0;
	while (mm[m])
	{
		n = 0;
		while (mm[m][n])
		{
			pr = process_map_line(cub, mm, m, n);
			if (pr == 1)
				return (1);
			else if (pr == 0)
				return (0);
			else if (pr == 99)
				break ;
			n++;
		}
		m++;
	}
	return (0);
}
