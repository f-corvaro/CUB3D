/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:24:15 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/26 22:58:55 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H	
# define TYPES_H

typedef struct s_window
{

}					t_window;

typedef struct s_texture
{

}					t_texture;

typedef struct s_player
{

}					t_player;

typedef struct s_assets
{

}					t_assets;

typedef struct s_camera
{

}					t_camera;

typedef struct s_raycasting
{

}					t_raycasting;

typedef struct s_minimap
{

}					t_minimap;

typedef struct s_time
{

}	t_time;

typedef struct s_engine
{
	void			*mlx;
	t_assets		assets;
	t_window		window;
	t_player		player;
	t_camera		camera;
	t_texture		world;
	t_raycasting	raycaster;
	t_minimap		mini_map;
	t_time			game_time;
}					t_engine;

#endif