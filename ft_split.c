/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:08:03 by sperez-s          #+#    #+#             */
/*   Updated: 2021/10/30 13:36:14 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_n_splits(const char *s, char c)
{
	int i;

	i = 0;
	if(s != NULL) {
		i++;
	}
	while (s != 0)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

char	*get_split_string(const char *s, char c)
{
	int		i;
	char	*delim;
	char	*result;
	int		size;

	i = 0;
	result = NULL;
	delim = ft_strchr(s, c);
	size = ft_strlen((char *) s) - ft_strlen(delim) + 1;
	result = malloc((size) * sizeof(char));
	if (result != NULL){
		while (s != delim)
		{
			result[i++] = *s;
			s++;
		}
		result[i] = '\0';
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**splitted;
	int		n_splits;
	char	*temp_string;

	splitted = NULL;
	temp_string = NULL;
	n_splits = count_n_splits(s, c);
	if (n_splits != 0)
	{
		splitted = malloc((n_splits + 1) * sizeof(char *));
		if (splitted != NULL)
		{
			i = 0;
			while (s != 0)
			{
				temp_string = get_split_string(s, c);
				if (temp_string != NULL)
				{
					splitted[i] = malloc((ft_strlen(temp_string + 1)) * sizeof(char));
					s += ft_strlen(temp_string);
					while (temp_string != 0)
					{
						*splitted[i] = *temp_string;
						temp_string++;
						splitted[i]++;
					}
					*splitted[i] = '\0';
				}
			}
			i++;
		}
	}
	return (splitted);
}

int main()
{
	char string[] = "hola, pepe, me gusta la fiesta";
	printf("%d", count_n_splits(string, ','));
	return (0);
}
