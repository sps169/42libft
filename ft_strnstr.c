/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:55:12 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/26 17:13:28 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_needle(char *haystack, char *needle)
{
	int	i;
	int	is_needle;

	i = 0;
	is_needle = 1;
	if (needle != NULL)
	{
		while (needle[i] != '\0')
		{
			if (haystack[i] != needle[i])
				is_needle = 0;
			i++;
		}
	}
	return (is_needle);
}

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	char	*first_occ;
	size_t		i;

	first_occ = NULL;
	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0] && i + ft_strlen(to_find) <= len)
		{
			first_occ = &str[i];
			if (is_needle(first_occ, to_find))
				return (first_occ);
			else
				first_occ = NULL;
		}
		i++;
	}
	return (first_occ);
}
