/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:37:05 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/24 20:25:43 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && result == 0 && i < n)
	{
		if (s1[i] != s2[i])
			result = ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (result);
}
