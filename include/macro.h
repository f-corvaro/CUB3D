/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:01:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:25:19 by fcorvaro         ###   ########.fr       */
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

#endif