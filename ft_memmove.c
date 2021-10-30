/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:04:39 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/26 15:46:16 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	counter;
	const char		*psource;
	char			*pdestiny;

	psource = (const char *) src;
	pdestiny = (char *) dst;
	counter = 0;
	if (pdestiny > psource)
	{
		counter = len;
		while (counter != 0)
		{
			pdestiny[counter - 1] = psource[counter - 1];
			counter--;
		}
	}
	else
	{
		while (counter < len)
		{
			pdestiny[counter] = psource[counter];
			counter++;
		}
	}
	return (dst);
}