/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:51 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 16:59:21 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismaj(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (ft_ismaj(c))
		return (c + 32);
	else
		return (c);
}
