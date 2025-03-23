/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:50:54 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 22:47:26 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	unsigned long	length;
	char			*mem;

	i = -1;
	length = ft_strlen(s);
	if (len > (length - start))
		len = length - start;
	if (start >= length)
	{
		mem = malloc(sizeof(char) * 1);
		if (mem == NULL)
			return (NULL);
		mem[0] = '\0';
		return (mem);
	}
	mem = malloc(sizeof(char) * len + 1);
	if (mem == NULL)
		return (NULL);
	while (++i < len)
		mem[i] = s[start + i];
	mem[i] = '\0';
	return (mem);
}
