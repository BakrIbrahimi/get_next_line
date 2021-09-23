/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:50:38 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/23 11:17:02 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// TODO: funcion que haga trim en el /n

static char	*return_next_line(char **s)
{
	char	*out;
	char	*tmp;
	size_t	len;

	len = 0;
	while ((*s)[len] != '\n' && !(*s)[len])
		len++;
	if ((*s)[len] == '\n')
	{
		out = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(*s + len + 1);
		free(*s);
		*s = tmp;
		if (!**s)
			free(*s); // TODO: ESTE FREE FALLA, HACE FREE DE COSAS QUE NO EXISTEN A VECES
	}
	else
	{
		out = ft_strdup(*s);
		if (!**s)
			free(*s);
	}
	return (out);
}

static char	*check_and_return(char **s, ssize_t n)
{
	if (!*s)
		return (NULL);
	if (n <= 0 && !*s) // necesario
	{
		free(*s);
		return (NULL);
	}
	return(return_next_line(s));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*s;
	ssize_t		n;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		if (!s)
			s = ft_strdup(buf);
		else
		{
			tmp = s;
			s = ft_strjoin(tmp, buf);
			free(tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (check_and_return(&s, n));
}
