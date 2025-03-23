/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:24:26 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 16:28:30 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;
	unsigned long	i;

	i = 0;
	f = (unsigned char *)s;
	while (i < n)
	{
		if (f[i] == (unsigned char) c)
			return (f + i);
		i++;
	}
	return (NULL);
}
