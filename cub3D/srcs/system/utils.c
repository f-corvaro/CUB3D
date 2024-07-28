/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:40:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/07/01 15:32:35 by fcorvaro         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * @brief Checks if the given string contains at least one digit.
 * 
 * @param str The input string to be checked for digits.
 * @return Returns true if the string contains at least one digit, 
 * otherwise returns false.
 */
bool	contains_digit(char *str)
{
	int		i;
	bool	res;

	res = false;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			res = true;
		i++;
	}
	return (res);
}

/**
 * @brief Checks if a character is a whitespace.
 * 
 * @param c The character to check.
 * @return 1 if the character is not a whitespace, 0 otherwise.
 */
int	is_a_white_space(char c)
{
	if (c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f'
		&& c != ' ')
		return (1);
	else
		return (0);
}

/**
 * @brief Finds the maximum line length in a map file starting from a 
 * given index.
 * 
 * @param map Pointer to the file data structure containing the file lines.
 * @param i The starting index for the search.
 * @return The length of the longest line found.
 */
size_t	get_max_line_len(t_map_data *file, int i)
{
	size_t	m_len;

	m_len = ft_strlen(file->file[i]);
	while (file->file[i])
	{
		if (ft_strlen(file->file[i]) > m_len)
			m_len = ft_strlen(file->file[i]);
		i++;
	}
	return (m_len);
}

/**
 * @brief Extracts a path from a given line starting at a specified position.
 *
 * This function scans a line of text starting from a given position, skipping
 * any leading whitespace or tab characters. It then extracts a substring that
 * represents a path, stopping at the next occurrence of whitespace, a tab, or
 * the newline character. The extracted path is dynamically allocated and must
 * be freed by the caller. If the line contains characters beyond the path 
 * before a newline, the function deems the line invalid, frees the allocated 
 * path, and returns NULL.
 *
 * @param line The line of text from which to extract the path.
 * @param pos The starting position within the line to begin extraction.
 * @return char* A dynamically allocated string containing the extracted path,
 * or NULL if the path is invalid or memory allocation fails.
 */
char	*extract_path(char *line, int pos)
{
	int		i;
	int		end;
	char	*path;

	while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
		pos++;
	end = pos;
	while (line[end] && (line[end] != ' ' && line[end] != '\t'))
		end++;
	path = malloc(sizeof(char) * (end - pos + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[pos] && (line[pos] != ' ' && line[pos] != '\t'
			&& line[pos] != '\n'))
		path[i++] = line[pos++];
	path[i] = '\0';
	while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
		pos++;
	if (line[pos] && line[pos] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}
