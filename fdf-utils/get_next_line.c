/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:13:43 by mbenouis          #+#    #+#             */
/*   Updated: 2025/03/14 14:13:44 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*bufferinit(char *buffer)
{
	if (buffer == NULL)
		buffer = ft_strdup("");
	return (buffer);
}

char	*concatbuffer(int fd, char *buffer)
{
	char	*bufftmp;
	int		stock;
	char	*newbuffer;

	stock = 1;
	buffer = (char *) bufferinit(buffer);
	bufftmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (stock > 0)
	{
		stock = read(fd, bufftmp, BUFFER_SIZE);
		if (stock == -1)
		{
			free(bufftmp);
			free(buffer);
			return (NULL);
		}
		bufftmp[stock] = '\0';
		newbuffer = ft_strjoin(buffer, bufftmp);
		free(buffer);
		buffer = newbuffer;
		if (ft_strchr(buffer, '\n') || stock == 0)
			break ;
	}
	free(bufftmp);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
	if (i == 0 && buffer[i] == '\0')
		return (NULL);
	line = ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
	{
		line[i] = '\n';
	}
	line[i + 1] = '\0';
	return (line);
}

char	*cleaner(char *buffer)
{
	int		i;
	int		k;
	char	*rest;

	i = 0;
	k = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	while (buffer[i] != '\0')
	{
		rest[k] = buffer[i];
		i++;
		k++;
	}
	rest[k] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*toprint;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	buffer = concatbuffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	toprint = get_line(buffer);
	if (toprint == NULL || toprint[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = cleaner(buffer);
	return (toprint);
}
/*
int main(void)
{
	int fd;

	fd = open("maps/map.fdf", O_RDONLY);
	if(fd == -1){
		printf("ERROR -1");
	}
	while(get_next_line(fd) != NULL)
	{
		printf("%s",get_next_line(fd));
	}
	close(fd);
}
*/
