/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:01:57 by sperez-s          #+#    #+#             */
/*   Updated: 2021/10/02 17:32:35 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_str_len(char const *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len] != 0)
			len++;
	}
	return (len);
}

short	is_set_character(char c, const char *set)
{
	int i;

	if (set != NULL)
	{
		i = 0;
		while(set[i] != 0)
		{
			if (set[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set){
	char			*new_str;
	size_t			new_str_len;
	unsigned int	start_bound;
	unsigned int	end_bound;
	unsigned int	i;

	start_bound = 0;
	end_bound = 0;
	if (get_str_len(s1) > 0)
	{
		end_bound = get_str_len(s1) - 1;
		while (is_set_character(s1[start_bound], set) && s1[start_bound + 1] != 0)
			start_bound++;
		while (is_set_character(s1[end_bound], set) && end_bound != start_bound)
			end_bound--;
	}
	if (start_bound - end_bound == 0)
		new_str_len = 0;
	else
		new_str_len = end_bound - start_bound + 1;
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		i = 0;
		while (i < new_str_len)
		{
			new_str[i] = s1[i + start_bound];
			i++;
		}
		new_str[i] = 0;
	}
	return (new_str);
}
