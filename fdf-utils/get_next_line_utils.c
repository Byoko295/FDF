/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:14:56 by mbenouis          #+#    #+#             */
/*   Updated: 2025/03/14 14:14:58 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;

	i = 0;
	k = (char *)s;
	if ((unsigned char)c == 0)
	{
		return (k + ft_strlen(s));
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (k + i);
		i++;
	}
	return (NULL);
}

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

char	*ft_strdup(const char *s)
{
	char			*save;
	unsigned long	i;

	if (s == NULL)
		return (NULL);
	save = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (save == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		save[i] = s[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
