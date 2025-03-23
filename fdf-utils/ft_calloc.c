/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:20:36 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 21:42:13 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*tab;
	unsigned long	i;

	tab = malloc(size * nmemb);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (i < (size * nmemb))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
