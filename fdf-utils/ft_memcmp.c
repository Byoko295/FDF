/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:50:02 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:44:02 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*f1;
	unsigned char	*f2;

	i = 0;
	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (i < n)
	{
		if (f1[i] > f2[i])
			return (1);
		else if (f1[i] < f2[i])
			return (-1);
		i++;
	}
	return (0);
}
