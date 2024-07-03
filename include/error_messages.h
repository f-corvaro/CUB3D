/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:41:47 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/03 11:08:16 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/**
 * @file error_messages.h
 * @brief Error message definitions for the cub3d project.
 *
 * This header file contains predefined error messages used throughout the
 * cub3d project. These messages are used to inform the user about various
 * errors that can occur during the execution of the program, such as invalid
 * input arguments, incorrect file formats, inability to open files, and
 * incorrect path types.
 */

# define ERR_MEM_A "Memory allocation failed."

/* ------------  INPUT ERRORS  ---------------------------------------------- */

# define INVALID_ARGS "Invalid number of arguments. "

# define INVALID_MAP_1 "Is a directory, expected a <map.cub>."

# define INVALID_MAP_2 "Usage: ./cub3d <path/to/map.cub>"

/* ------------  MAP ERRORS  ------------------------------------------------ */

# define ERR_INV_MAP_1 "Invalid character found in map."

# define ERR_INV_MAP_2 "Invalid map format."

# define ERR_SPAWN_1 "Multiple player starting positions detected."

# define ERR_SPAWN_2 "Map lacks a player spawn point."

# define ERR_SPAWN_3 "Invalid player position."

# define ERR_MAP_1 "Map data is missing."

# define ERR_MAP_2 "Map borders must be enclosed by walls."

# define ERR_MAP_3 "Map must be at least 3 lines high."

# define ERR_MAP_4 "Map data must be the last element in the file."

/* ------------  MLX ERRORS  ------------------------------------------------ */

# define MLX_START "Failed to initialize MiniLibX"

# define MLX_IMG "Failed to create MiniLibX image"

# define MLX_WIN "Failed to create MiniLibX window"

/* ------------  TEXTURES ERRORS  ------------------------------------------- */

# define INVALID_XPM_1 "Is a directory, expected a <texture.xpm>."

# define INVALID_XPM_2 "Expected a <texture.xpm>."

# define ERR_RGB "RGB value out of valid range (0-255)."

# define ERR_TEX_FORMAT_1 "One or more texture paths are missing."

# define ERR_TEX_FORMAT_2 "Floor or ceiling color is missing."

#endif
