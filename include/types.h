/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:24:15 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 13:12:49 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H	
# define TYPES_H

typedef struct s_window
{

}					t_window;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height; 
	bool		free;
}				t_texture;

typedef struct s_player
{

}				t_player;

typedef struct s_assets
{

}				t_assets;

typedef struct s_camera
{

}				t_camera;

typedef struct s_raycasting
{

}				t_raycasting;

typedef struct s_minimap
{

}				t_minimap;

typedef struct s_time
{

}				t_time;

typedef struct s_cube
{
	void			*mlx;
	char			**map;
	char			**elements;
	int				fd;
	int				floor_color[3]; // 0 = R, 1 = G, 2 = B
	int				ceiling_color[3]; // 0 = R, 1 = G, 2 = B
	t_assets		assets;
	t_window		window;
	t_player		player;
	t_camera		camera;
	t_texture		texture[4]; // 0 = NO, 1 = SO, 2 = WE, 3 = EA
	t_raycasting	raycaster;
	t_minimap		mini_map;
	t_time			game_time;
}					t_cube;

#endif