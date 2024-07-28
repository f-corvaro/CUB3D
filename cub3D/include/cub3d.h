/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:09:34 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/30 15:52:44 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/**
 * @file cub3d.h
 * @brief Main header file for the Cub3D project.
 *
 * This header file includes all the necessary libraries and other header files 
 * required for the Cub3D project.
 *
 */

/* ------------  LIBRARIES INCLUDED  ---------------------------------------- */

# include "../lib/libftprintf/include/ft_printf.h"

# ifdef __linux__
#  include "../lib/mlx_linux/mlx.h"
# endif

# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <unistd.h>

/* ------------  HEADER FILE INCLUDED  -------------------------------------- */

# include "error_messages.h"
# include "functions.h"
# include "key_mapping.h"
# include "macro.h"
# include "resolution_config.h"
# include "types.h"

#endif