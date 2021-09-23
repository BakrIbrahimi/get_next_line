/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:33:48 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/23 19:57:56 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*save;
	size_t	len;

	len = ft_strlen(s1);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	save = cpy;
	while (*s1)
		*cpy++ = *s1++;
	*cpy = '\0';
	return (save);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*save;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	save = out;
	while (*s1)
		*out++ = *s1++;
	while (*s2)
		*out++ = *s2++;
	*out = '\0';
	return (save);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	out_len;
	char	*save;
	char	*out;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	out_len = ft_strlen(s + start);
	if (out_len < len)
		len = out_len;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	save = out;
	s += start;
	while (*s && len--)
		*out++ = *s++;
	*out = '\0';
	return (save);
}
