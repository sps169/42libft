/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:34:26 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/19 13:08:38 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	char			*char_destiny;
	char			*char_source;

	i = 0;
	char_destiny = (char *) dst;
	char_source = (char *) src;
	while (i < n)
	{
		char_destiny[i] = char_source[i];
		i++;
	}
	return (dst);
}
