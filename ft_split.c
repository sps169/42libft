/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:08:03 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/20 14:31:01 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_n_splits(char const *s, char delim)
{
	int	n_splits;
	int	i;
	int	word_found;

	n_splits = 0;
	i = 0;
	word_found = 0;
	while (s[i] != 0)
	{
		while (s[i] == delim)
			i++;
		while (s[i] != delim && s[i] != 0)
		{
			i++;
			word_found = 1;
		}
		if (word_found)
		{
			n_splits++;
			word_found = 0;
		}
	}
	return (n_splits);
}

static int save_string(const char *s, char *string, int end, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		string[i] = s[end - len + i];
		i++;
	}
	string[i] = '\0';
	return (0);
}

static void	free_matrix(char **matrix, int index, int n_splits)
{
	int i;

	i = 0;
	while (i < index) {
		free(matrix[i++]);
	}
	free(matrix[n_splits]);
	free(matrix);
}

static int	run_string(const char *s, char **matrix, char delim, int n_splits)
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
			matrix[string_index] = malloc((current_length + 1) * sizeof(char));
			if (matrix[string_index] == NULL)
				return (-1);
			if (save_string(s, matrix[string_index], i, current_length) == -1)
			{
				free_matrix(matrix, string_index, n_splits);
				return (-1);
			}
			string_index++;
			current_length = -1;
		}
		else if (s[i] == delim && current_length == 0)
			current_length = -1;
		current_length++;
		i++;
	}
	if (current_length != 0)
	{
		if (save_string(s, matrix[string_index], i, current_length) == -1)
		{
			free_matrix(matrix, string_index, n_splits);
			return (-1);
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		n_splits;
	char	**matrix;

	n_splits = 0;
	matrix = NULL;
	n_splits = count_n_splits(s, c);
	if (n_splits == 0)
		return (NULL);
	matrix = malloc((n_splits + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	matrix[n_splits] = NULL;
	run_string(s, matrix, c, n_splits);
	return (matrix);
}

// int main() {
// 	char string[] = "    hello mr    dude    ";
// 	char **matrix = ft_split(string, ' ');
// 	int i = 0;
// 	while (i < 4)
// 	{
// 		printf("String at pos %d: %s\n",i, matrix[i]);
// 		i++;
// 	}
// 	return (0);
// }
