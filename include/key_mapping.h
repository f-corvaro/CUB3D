/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:56:06 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:31:36 by fcorvaro         ###   ########.fr       */
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
 *   - RIGHT_ARROW: Right arrow key
 * - Movement:
 *   - MOVE_UP: 'W' key
 *   - MOVE_LEFT: 'A' key
 *   - MOVE_DOWN: 'S' key
 *   - MOVE_RIGHT: 'D' key
 * - Actions:
 *   - ACTION_EXIT: Escape key
 */

# ifdef __linux__

#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363

#  define MOVE_LEFT 97
#  define MOVE_RIGHT 100
#  define MOVE_DOWN 115
#  define MOVE_UP 119

#  define ACTION_EXIT 65307

# endif

/* ------------  CONTROL INFORMATION TEXT  ---------------------------------- */

/**
 * @brief Menu title for the control information display.
 */
# define MENU_T "=== Control Information ==="

/**
 * @brief Description of the key to exit the game.
 */
# define CLOSE "-> ESC or Close Button: Exit the Game"

/**
 * @brief Description of rotation controls.
 */
# define ROTATE "--> Arrow Keys (Left/Right): Rotate (Left/Right)"

/**
 * @brief Description of movement controls.
 */
# define MOVE "---> WASD: Move (W: Forward, A: Left, S: Backward, D: Right)"

/* ------------  CONTROL INFORMATION DISPLAY POSITION  ---------------------- */

/**
 * @brief Starting X coordinate for displaying control information.
 */
# define START_X 25

/**
 * @brief Starting Y coordinate for displaying control information.
 */
# define START_Y 20

/**
 * @brief Line spacing for displaying control information.
 */
# define LINE_SPACING 20

#endif