/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:41:47 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/29 14:45:58 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERROR_MSG_INVALID_ARGS "Error: Invalid number of arguments. \
								Usage: ./cub3d <path/to/map.cub>"

# define ERROR_INVALID_EXTENSION "Error: The map file is in the wrong format. \
								Please use a valid file extension. \
								Usage: ./cub3d <path/to/map.cub>"

# define ERROR_UNABLE_TO_OPEN "Error: Unable to open the map. \
								Possible reasons include: \
								file does not exist, incorrect permissions, \
								or the file is in use."

#endif