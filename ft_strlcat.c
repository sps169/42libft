/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:47:29 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/24 20:33:23 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	append(char *dst, const char *src, size_t size, size_t dest_size)
{
	unsigned int	i;

	i = 0;
	while (i < size - dest_size - 1 && src[i] != '\0')
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = 0;
	src_size = 0;
	i = 0;
	if ((dst != NULL || src != NULL) && size != 0)
	{
		while (dst[i++] != '\0')
			dest_size++;
		i = 0;
		while (src[i++] != '\0')
			src_size++;
	}
	if ((dst != NULL && src != NULL) && size != 0 && dest_size < size)
	{
		append(dst, src, size, dest_size);
	}
	if (dest_size > size)
		dest_size = size;
	return (dest_size + src_size);
}
