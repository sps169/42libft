/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:56:18 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/18 18:59:15 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	char			*d;

	d = (char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (char)c;
		i++;
	}
	return (b);
}
