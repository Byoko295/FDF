/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:02:57 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 22:54:14 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	char			*t;
	unsigned long	toalloc;

	toalloc = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	t = malloc(sizeof(char) * toalloc + 1);
	i = -1;
	j = 0;
	if (t == NULL)
		return (NULL);
	while (s1[++i])
		t[i] = s1[i];
	while (s2[j])
	{
		t[i] = s2[j];
		j++;
		i++;
	}
	t[i] = '\0';
	return (t);
}
