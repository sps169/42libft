/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdrup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:54:16 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/26 17:59:37 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	int		i;
	char	*src;

	src = (char *) s1;
	string = malloc(ft_strlen(src)*sizeof(char));
	if (string != NULL)
	{
		i = 0;
		while (s1[i] != 0)
		{
			string[i] = s1[i];
			i++;
		}
		string[i] = '\0';
	}
	return (string);
}
