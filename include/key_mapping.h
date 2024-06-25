/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:56:06 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/25 22:12:56 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAPPING_H
# define KEY_MAPPING_H

/**
 * @file key_mapping.h
 * @brief Defines key mappings for various actions on Linux systems.
 *
 * This header file contains macro definitions for keyboard keys used in cub3d. 
 *
 * @note These mappings are specific to Linux systems.
 *
 * Key Mappings:
 * - Navigation:
 *   - LEFT_ARROW: Left arrow key
 *   - UP_ARROW: Up arrow key
 *   - RIGHT_ARROW: Right arrow key
 *   - DOWN_ARROW: Down arrow key
 * - Movement:
 *   - MOVE_UP: 'W' key
 *   - MOVE_LEFT: 'A' key
 *   - MOVE_DOWN: 'S' key
 *   - MOVE_RIGHT: 'D' key
 * - Actions:
 *   - ACTION_EXIT: Escape key
 *   - ACTION_MINIMAP: 'M' key
 */

# ifdef __linux__

#  define LEFT_ARROW 65361
#  define UP_ARROW 65362
#  define RIGHT_ARROW 65363
#  define DOWN_ARROW 65364

#  define MOVE_LEFT 97
#  define MOVE_RIGHT 100
#  define MOVE_DOWN 115
#  define MOVE_UP 119

#  define ACTION_EXIT 65307
#  define ACTION_MINIMAP 109

# endif

#endif