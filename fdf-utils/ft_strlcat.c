/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:34:28 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:44:45 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	leng;

	leng = ft_strlen(s1);
	i = 0;
	if (leng >= n)
		return ((size_t)ft_strlen(s2) + n);
	while (s2[i] && (size_t)i < (n - leng - 1))
	{
		s1[i + leng] = s2[i];
		i++;
	}
	s1[i + leng] = '\0';
	return ((size_t)ft_strlen(s2) + leng);
}
