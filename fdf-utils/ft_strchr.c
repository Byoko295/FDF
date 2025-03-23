/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:34:09 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:44:28 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;

	i = 0;
	k = (char *)s;
	if ((unsigned char)c == 0)
	{
		return (k + ft_strlen(s));
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (k + i);
		i++;
	}
	return (NULL);
}
