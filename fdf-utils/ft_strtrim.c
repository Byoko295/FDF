/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:37:57 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 22:49:27 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimmer(char c, char const *set)
{
	unsigned long	i;

	i = 0;
	while (i < (unsigned long)ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && istrimmer(s1[start], set))
		start++;
	while (s1[end - 1] && istrimmer(s1[end - 1], set) && end > start)
		end--;
	s = malloc(sizeof(char) * (end - start) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s[i] = s1[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
