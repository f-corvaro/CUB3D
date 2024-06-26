/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:25:42 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/26 22:37:33 by fcorvaro         ###   ########.fr       */
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
typedef struct s_game_engine	t_engine;

/* ------------  FUNCTIONS DECLARED  ---------------------------------------- */

void		terminate(char *msg, t_engine *cub);


#endif