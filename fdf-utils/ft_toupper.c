/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:49:22 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/07 17:18:02 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_ismin(int c)
{
	if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_ismin(c))
		return (c - 32);
	else
		return (c);
}
