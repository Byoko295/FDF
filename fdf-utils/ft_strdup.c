/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:48:18 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:44:33 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*save;
	unsigned long	i;

	save = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (save == NULL)
		return (NULL);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		save[i] = s[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
