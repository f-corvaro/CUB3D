/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:24:15 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:30 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H	
# define TYPES_H

/**
 * @struct s_img
 * @brief Structure for image data management.
 *
 * This structure is used to hold and manage image data and properties
 * necessary for image processing and manipulation.
 *
 * @param img Pointer to the image data.
 * @param addr Pointer to the first pixel's address.
 * @param endian Indicates the endianness of the pixel data.
 * @param pix_bits Number of bits per pixel.
 * @param size_line Size of one line of the image in bytes.
 */
typedef struct s_img
{
	void	*img;
	int		*addr;
	int		endian;
	int		pix_bits;
	int		size_line;
}			t_img;

/**
 * @struct s_map_data
 * @brief Structure for map data management.
 *
 * @param fd File descriptor for the map file.
 * @param line_count The number of lines in the map file.
 * @param height The height of the map.
 * @param width The width of the map.
 * @param eom Index indicating the end of the map data within the file.
 * @param path Path to the map file.
 * @param file Array of strings, each representing a line in the map file.
 */
typedef struct s_map_data
{
	int			fd;
	int			line_count;
	int			height;
	int			width;
	int			eom;
	char		*path;
	char		**file;
}				t_map_data;

/**
 * @struct s_texture
 * @brief Structure for texture data management.
 *
 * This structure is used to hold and manage texture data and properties
 * necessary for texture mapping and manipulation in 3D.
 *
 * @param size The size of the texture.
 * @param index The index of the texture in a collection.
 * @param floor Pointer to the floor texture data.
 * @param ceiling Pointer to the ceiling texture data.
 * @param x The x-coordinate of the texture in the texture space.
 * @param y The y-coordinate of the texture in the texture space.
 * @param north Pointer to the north wall texture path.
 * @param south Pointer to the south wall texture path.
 * @param west Pointer to the west wall texture path.
 * @param east Pointer to the east wall texture path.
 * @param step The step increment for texture mapping.
 * @param pos The current position in the texture mapping process.
 * @param hex_f The hexadecimal color value for the floor.
 * @param hex_c The hexadecimal color value for the ceiling.
 */
typedef struct s_texture
{
	int				size;
	int				index;
	int				*floor;
	int				*ceiling;
	int				x;
	int				y;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	double			step;
	double			pos;
	unsigned long	hex_f;
	unsigned long	hex_c;
}					t_texture;

/**
 * @struct t_player
 * @brief Represents a player in the game environment.
 *
 * @param has_moved Indicates if the player has moved since the last frame 
 * (1 for yes, 0 for no).
 * @param dx The change in the player's x-coordinate due to movement.
 * @param dy The change in the player's y-coordinate due to movement.
 * @param rotation The player's current rotation or facing direction.
 * @param u_v A character representing the unit vector for additional player 
 * state.
 * @param x0 The player's current x-coordinate.
 * @param y0 The player's current y-coordinate.
 * @param dir_x The x-component of the player's direction vector.
 * @param dir_y The y-component of the player's direction vector.
 * @param plane_x The x-component of the player's camera plane vector.
 * @param plane_y The y-component of the player's camera plane vector.
 */
typedef struct s_player
{
	int		has_moved;
	int		dx;
	int		dy;
	int		rotation;
	char	u_v;
	double	x0;
	double	y0;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

/**
 * @struct t_raycast
 * @brief Represents the raycasting calculations for rendering a scene.
 *
 * @param hit_side Indicates which side of the wall was hit.
 * @param map_x The x-coordinate of the square in the map that the ray has hit.
 * @param map_y The y-coordinate of the square in the map that the ray has hit.
 * @param step_x The direction to step in x-axis (-1, 1) during raycasting.
 * @param step_y The direction to step in y-axis (-1, 1) during raycasting.
 * @param draw_start The start position of the vertical line to draw for this 
 * ray.
 * @param draw_end The end position of the vertical line to draw for this ray.
 * @param line_height The height of the line to draw for this ray.
 * @param camera_x The x-coordinate in camera space for the ray.
 * @param dir_x The x-component of the ray direction vector.
 * @param dir_y The y-component of the ray direction vector.
 * @param sidedist_x The distance the ray has to travel to cross one x-axis grid.
 * @param sidedist_y The distance the ray has to travel to cross one y-axis grid.
 * @param deltadist_x The distance the ray has to travel to move from one x-grid
 * to the next x-grid.
 * @param deltadist_y The distance the ray has to travel to move from one y-grid
 * to the next y-grid.
 * @param wall_dist The distance from the camera to the wall hit by the ray.
 * @param wall_x The exact position where the wall was hit by the ray, used for
 * texture mapping.
 */
typedef struct s_raycast
{
	int		hit_side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
}			t_raycast;

/**
 * @struct s_engine
 * @brief Represents the main engine structure for the game, 
 * holding all essential data.
 *
 * @param mlx Pointer to the MLX library instance, 
 * used for managing graphics.
 * @param win Pointer to the window created with MLX, 
 * where graphics are rendered.
 * @param win_h Height of the window in pixels.
 * @param win_w Width of the window in pixels.
 * @param tex_data Pointer to an array of texture data, 
 * where each entry is a pointer to the pixel data of a texture.
 * @param tex_ids Pointer to an array of texture identifiers, 
 * used for texture mapping.
 * @param map Pointer to an array of strings representing the game map, 
 * where each string is a row of the map.
 * @param m_data An instance of t_map_data, holding data specific to the map, 
 * such as dimensions.
 * @param player An instance of t_player, representing the player's state, 
 * including position and orientation.
 * @param result An instance of t_raycast, holding the result of the last 
 * raycasting operation, used for rendering.
 * @param t An instance of t_texture, representing texture information,
 * including pointers to texture data.
 */
typedef struct s_engine
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			**tex_data;
	int			**tex_ids;
	char		**map;
	t_map_data	m_data;
	t_player	player;
	t_raycast	result;
	t_texture	t;
}				t_engine;

#endif