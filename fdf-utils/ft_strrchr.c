/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:11:42 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:45:13 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *c, int k)
{
	int				i;
	unsigned char	v;

	v = (unsigned char)k;
	i = ft_strlen(c);
	while (i >= 0)
	{
		if (c[i] == v)
			return ((char *)c + i);
		i--;
	}
	return (NULL);
}
