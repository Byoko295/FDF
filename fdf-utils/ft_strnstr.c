/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:35:12 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 14:30:41 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	size_t			y;
	unsigned int	b;
	unsigned int	sizel;

	sizel = ft_strlen(little);
	y = 0;
	if (sizel == 0)
		return ((char *)big);
	while (big[y] && (y < n))
	{
		b = 0;
		i = 0;
		while (i < sizel && (y + i) < n)
		{
			if (little[i] == big[y + i])
				b++;
			i++;
		}
		if (b == sizel)
			return ((char *)big + y);
		y++;
	}
	return (NULL);
}
