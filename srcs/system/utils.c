/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:01:48 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 15:20:31 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Compares two strings.
 * 
 * This function compares the string pointed to by s1 to the string pointed to
 * by s2.
 * 
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * @brief Print error message and exit the program
 *
 * @param msg Error message
 * @param cube Struct with game data
 */

void	error_exit(char *msg, t_cube *cube)
{
	ft_putstr_fd(ft_strjoin(msg, "\n"), STDERR_FILENO);
	close_game(cube);
}
