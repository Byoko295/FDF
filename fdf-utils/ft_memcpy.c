/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:37:29 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:43:51 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*k;
	const unsigned char	*v;

	k = dest;
	v = src;
	i = 0;
	if (k == NULL && v == NULL)
		return (NULL);
	while (i < n)
	{
		k[i] = v[i];
		i++;
	}
	return (dest);
}
