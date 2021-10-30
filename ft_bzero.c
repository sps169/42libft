/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:55:39 by sperez-s          #+#    #+#             */
/*   Updated: 2021/09/26 14:16:11 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	char			*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}
