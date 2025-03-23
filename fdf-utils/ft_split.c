/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <mbenouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:08:14 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/08 00:55:49 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	compter_mots(const char *str, char sep)
{
	size_t	nombre_mots;
	size_t	i;

	nombre_mots = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			nombre_mots++;
		i++;
	}
	return (nombre_mots);
}

static void	liberer_memoire(char **tableau)
{
	size_t	indice;

	indice = 0;
	if (!tableau)
		return ;
	while (tableau[indice])
	{
		free(tableau[indice]);
		indice++;
	}
	free(tableau);
}

static int	allouer_mots(char **tableau, const char *str, char separateur)
{
	size_t		indice;
	const char	*debut;

	indice = 0;
	while (*str)
	{
		while (*str == separateur)
			str++;
		debut = str;
		while (*str && *str != separateur)
			str++;
		if (str > debut)
		{
			tableau[indice] = ft_substr(debut, 0, str - debut);
			if (!tableau[indice])
			{
				liberer_memoire(tableau);
				return (-1);
			}
			indice++;
		}
	}
	tableau[indice] = NULL;
	return (0);
}

char	**ft_split(const char *str, char c)
{
	size_t	nombre_mots;
	char	**tableau;

	if (!str)
		return (NULL);
	nombre_mots = compter_mots(str, c);
	tableau = malloc(sizeof(char *) * (nombre_mots + 1));
	if (!tableau || allouer_mots(tableau, str, c) == -1)
		return (NULL);
	return (tableau);
}
