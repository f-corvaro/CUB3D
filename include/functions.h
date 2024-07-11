/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:25:42 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:28:01 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H	
# define FUNCTIONS_H

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

typedef struct s_img		t_img;
typedef struct s_raycast	t_raycast;
typedef struct s_player		t_player;
typedef struct s_map_data	t_map_data;
typedef struct s_texture	t_texture;
typedef struct s_engine		t_engine;

/* ------------  FUNCTIONS DECLARED  ---------------------------------------- */

/* ------------  MAP  ------------------------------------------------------- */

/* map/borders.c */

int		validate_map_wall(t_map_data *map, char **mm);

/* map/init_and_loading.c */

int		setup_mm(t_engine *cub, char **mm, int i);

/* map/operations.c*/

void	convert_siw(t_engine *cub);

/* map/parser.c */

void	lns_map(char *path, t_engine *cub);
int		check_map_is_at_the_end(t_map_data *map);
int		set_fnc_color(t_engine *cub, t_texture *t, char *line, int i);
int		process_map_data(t_engine *cub, char **mm);

/* map/player.c*/

int		set_n_validate_pp(t_engine *cub, char **mm);

/* map/utils.c */

void	build_map_matrix(int m, int n, int i, t_engine *cub);
int		count_map_lines(char *path);

/* map/validation.c */

int		validate_map_data(t_engine *cub, char **mm);

/* ------------  MLX  ------------------------------------------------------- */
/* mlx/init.c */

void	init_mlx(t_engine *cub);
void	init_img(t_engine *cub, t_img *img, int w, int h);
void	init_texture_img(t_engine *cub, t_img *img, char *path);

/* ------------  PLAYER  ---------------------------------------------------- */

/* player/actions.c */

void	init_player_direction(t_engine *cub);
int		process_rotation(t_engine *cub, double direction);
int		process_movement(t_engine *cub);

/* player/input_key.c */

void	input_handle(t_engine *cub);

/* player/position.c */

int		move_check(t_engine *cub, double x1, double y1);

/* ------------  RAYCAST  --------------------------------------------------- */

/* raycast/dda.c */

void	execute_dda(t_engine *cub, t_raycast *r);

/* raycast/init.c */

void	init_raycast(t_raycast *state);
void	init_ray_state(int x, t_raycast *r, t_player *p);
void	init_dda(t_raycast *r, t_player *p);
void	set_player_dir_ns(t_player *state);
void	set_player_dir_ew(t_player *state);

/* raycast/player_movement.c*/

int		advance_position(t_engine *cub);
int		retreat_position(t_engine *cub);
int		strafe_left(t_engine *cub);
int		strafe_right(t_engine *cub);
int		rotate_view(t_engine *cub, double speed);

/* raycast/render_engine.c */

void	exe_raynren(t_engine *cub);
int		upnren_frame(t_engine *cub);

/* raycast/render_utils.c */

void	apply_to_pix(t_engine *cub, t_img *img, int x, int y);
void	render_scene(t_engine *cub);
void	calc_texindex(t_engine *cub, t_raycast *r);

/* raycast/utils.c*/

bool	is_valid_pos(t_engine *cub, double x1, double y1);

/* raycast/wall_projection_calculator.c */

void	calc_wall_projection(t_raycast *r, t_engine *cub, t_player *p);

/* ------------  SYSTEM  ---------------------------------------------------- */
/* system/cleanup_op.c */

void	free_texture(t_texture *texture);
void	free_matrix(void **matrix);
void	free_map(t_engine *cub);
int		free_cub(t_engine *cub);

/* system/close_game.c */

int		close_game(t_engine *cub);

/* system/error_handling.c */

int		error_exit(char *t_err, char *a_info, int exit_code);

/* system/init.c */

void	setup_engine(t_engine *cub);
//sistema
int		init_game(t_engine *cub, char **av);

/* system/input_validation.c */

bool	is_a_dir(char *path);
int		check_input_path(t_engine *cub, char **av);

/* system/menu.c */

void	draw_control_info(t_engine *cub);

/* system/shutdown_game.c*/

void	shutdown_cub(t_engine *cub, int exit_code);

/* system/utils.c */

int		ft_strcmp(const char *s1, const char *s2);
bool	contains_digit(char *str);
int		is_a_white_space(char c);
size_t	get_max_line_len(t_map_data *file, int i);
char	*extract_path(char *line, int pos);

/* system/utils2.c */

void	set_pixel_color(t_img *img, int x, int y, int color);
bool	is_xpm_file(char *path);
int		*parse_rgb(char *line);

/* ------------  TEXTURE  --------------------------------------------------- */

/* texture/convert_and_load.c */

void	load_texture(t_engine *cub);
void	texture_update(t_engine *cub, t_texture *t, t_raycast *r, int x);

/* texture/init.c */

void	init_texpix(t_engine *cub);
int		assign_t_path(t_texture *t, char *line, int i);

/* texture/validation.c */

int		texture_validation(t_engine *cub, t_texture *t);

#endif