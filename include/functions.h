/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:25:42 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 15:21:46 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H	
# define FUNCTIONS_H

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

typedef struct s_window			t_window;
typedef struct s_texture		t_texture;
typedef struct s_player			t_player;
typedef struct s_assets			t_assets;
typedef struct s_camera			t_camera;
typedef struct s_raycasting		t_raycasting;
typedef struct s_minimap		t_minimap;
typedef struct s_time			t_time;
typedef struct s_cube			t_cube;

/* ------------  FUNCTIONS DECLARED  ---------------------------------------- */

int		ft_strcmp(const char *s1, const char *s2);
void	error_exit(char *msg, t_cube *cube);

void	check_args(int ac, const char **av, t_cube *cub);

/*da rivedere*/

void	close_game(t_cube *cube);


/* ========================================================================== */
/*               CHECK_ARGS                                                   */
/* ========================================================================== */

/* ========================================================================== */
/*               ELEMENTS                                                     */
/* ========================================================================== */

/* ========================================================================== */
/*               EXIT                                                         */
/* ========================================================================== */



/* ========================================================================== */
/*               FREE                                                         */
/* ========================================================================== */

/* ========================================================================== */
/*               INIT                                                         */
/* ========================================================================== */

/* ========================================================================== */
/*               MAP                                                          */
/* ========================================================================== */

#endif