/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:49:45 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/08 00:15:51 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*casarticulier(int nb)
{
	char	*ret;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
	{
		ret = malloc(sizeof(char) + 1);
		if (ret == NULL)
			return (NULL);
		ret[0] = 48;
		ret[1] = '\0';
		return (ret);
	}
	return (NULL);
}

static char	*memand(int l, int k, int nb)
{
	int		i;
	char	*ret;

	i = l;
	ret = malloc(sizeof(char) * l + k + 2);
	if (ret == NULL)
		return (NULL);
	if (k == 1)
		ret[0] = '-';
	while (nb > 0)
	{
		ret[i + k] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	ret[l + k + 1] = '\0';
	return (ret);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		check;
	int		l;
	int		k;

	k = 0;
	check = nb;
	if (nb == -2147483648 || nb == 0)
		return (casarticulier(nb));
	if (nb < 0)
	{
		check = check * (-1);
		nb = nb * (-1);
		k = 1;
	}
	i = 0;
	while (check > 9)
	{
		check = check / 10;
		i++;
	}
	l = i;
	return (memand(l, k, nb));
}
