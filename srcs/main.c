/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:11:59 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/11 16:47:29 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_arguments(int ac)
{
	if (ac != 2)
		return (error_exit("USAGE", INVALID_ARGS, 1));
	return (0);
}

static int	initialize_engine(t_engine *cub, char **av)
{
	setup_engine(cub);
	if (check_input_path(cub, av) != 0)
		return (1);
	if (init_game(cub, av) != 0)
		return (1);
	init_mlx(cub);
	load_texture(cub);
	return (0);
}

static void	run_game_loop(t_engine *cub)
{
	exe_raynren(cub);
	input_handle(cub);
	mlx_loop_hook(cub->mlx, upnren_frame, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_engine	cub;

	printf("%s\n", CUB_ART);
	printf("%s\n", MSG_START);
	if (check_arguments(ac) == 1)
		return (1);
	printf("%s\n", MSG_LOADING);
	if (initialize_engine(&cub, av) == 1)
		return (1);
	run_game_loop(&cub);
	return (0);
}
