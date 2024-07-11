/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:01:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:49:33 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/**
 * @def PMS
 * Player Movement Speed (PMS) defines the speed at which the player moves.
 *
 */
# define PMS 0.02

/**
 * @def PRS
 * Player Rotation Speed (PRS) defines the speed of player's rotation.
 */
# define PRS 0.01

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define M_ELEM "10NSEW"
# define P_DIR "NSEW"

# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF

# define CUB_ART "\033[33m\n\
                    ,,                              \n\
                   *MM                 `7MM\"\"\"Yb.   \n\
                    MM                   MM    `Yb. \n\
 ,p6\"bo `7MM  `7MM  MM,dMMb.   pd\"\"b.    MM     `Mb \n\
6M'  OO   MM    MM  MM    `Mb (O)  `8b   MM      MM \n\
8M        MM    MM  MM     M8      ,89   MM     ,MP \n\
YM.    ,  MM    MM  MM.   ,M9    \"\"Yb.   MM    ,dP' \n\
 YMbmd'   `Mbod\"YML.P^YbmdP'        88 .JMMmmmdP'   \n\
                              (O)  .M'              \n\
                               bmmmd'               \n\033[0m" 

# define MSG_START "\033[33mcub3D: Starting the game...\033[0m"
# define MSG_LOADING "\033[33mcub3D: Loading resources...\033[0m"
# define MSG_END "\033[32mcub3D: Exiting the game...\033[0m"

#endif