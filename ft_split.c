/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:08:03 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/18 20:17:03 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*trim(const char *s, char delim)
{
	char	*trimmed;
	char	*delim_string;

	delim_string = malloc(2 * sizeof(char));
	if (delim_string != NULL)
	{
		trimmed = NULL;
		trimmed = ft_strtrim(s, ft_memset(delim_string, delim, 1));
		if (trimmed != NULL)
		{
			return (trimmed);
		}
		free(delim_string);
	}
	return (NULL);
}

static int	count_n_splits(char const *s, char delim)
{
	int	n_splits;
	int	i;
	int	delim_found;

	n_splits = 0;
	i = 0;
	delim_found = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delim && delim_found == 0)
		{
			n_splits++;
			delim_found = 1;
		}
		else
			delim_found = 0;
		i++;
	}
	return (n_splits + 1);
}

static char	**init_matrix(int n_splits, char **matrix)
{
	matrix = malloc((n_splits + 1) * sizeof(char *));
	if (matrix != NULL)
	{
		matrix[n_splits] = NULL;
	}
	return (matrix);
}

static int save_string(const char *s, char**matrix, int index, int end, int len)
{
	int	control;
	int	i;

	i = 0;
	matrix[index] = malloc((len + 1) * sizeof(char));
	if (matrix[index] != NULL)
	{
		while (i < len)
		{
			matrix[index][i] = s[end - len + i];
			i++;
		}
		matrix[index][i] = '\0';
	}
	else
		control = -1;
	control = 0;
	return (control);
}

static void	free_matrix(char **matrix, int index)
{
	int i;

	i = 0;
	while (i < index)
		free(matrix[i++]);
	free(matrix);
}

static void	run_string(const char *s, char **matrix, char delim)
{
	int	i;
	int	current_length;
	int	string_index;

	i = 0;
	current_length = 0;
	string_index = 0;
	while (s[i] != 0)
	{
		if (s[i] == delim && current_length != 0)
		{
			if (save_string(s, matrix, string_index, i, current_length) == -1)
				free_matrix(matrix, string_index);
			string_index++;
			current_length = -1;
		}
		current_length++;
		i++;
	}
	if (current_length != 0) {
		if (save_string(s, matrix, string_index, i, current_length) == -1)
			free_matrix(matrix, string_index);
	}
}

char	**ft_split(char const *s, char c)
{
	char	*trimmed;
	int		n_splits;
	char	**matrix;

	n_splits = 0;
	matrix = NULL;
	trimmed = NULL;
	trimmed = trim(s, c);
	if (trimmed != NULL)
	{
		n_splits = count_n_splits(trimmed, c);
		matrix = init_matrix(n_splits, matrix);
		if (matrix != NULL)
			run_string(trimmed, matrix, c);
		free(trimmed);
	}
	return (matrix);
}

int main()
{
	int i = 0;
	char string[] = "  tripouille  42  ";
	char **matrix;
	matrix = NULL;
	matrix = ft_split(string, ' ');
	while (i < 3)
	{
		printf("%s\n",matrix[i]);
		i++;
	}
	return (0);
}
