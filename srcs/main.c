/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:09:12 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/26 22:47:57 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_engine	cub;

	/*something to init cub*/
	if (ac != 2)
		terminate(ERROR_MSG_INVALID_ARGS, &cub);
	else
	{
		/*something to check if the map is valid*/
		/*something to load the map*/
		/*something to start the game*/
	}
}
