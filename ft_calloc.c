/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:29:25 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/24 21:21:12 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*pmemory;
	size_t	i;

	pmemory = malloc(count * size);
	if (pmemory != NULL)
	{
		i = 0;
		while (i < count * size)
		{
			pmemory[i] = 0;
			i++;
		}
	}
	return (pmemory);
}
