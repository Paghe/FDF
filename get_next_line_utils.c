/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:33:44 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/03 18:39:07 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdupgn(char *s)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s)
		return (free(s), NULL);
	s2 = ft_calloc(sizeof(char), ft_strl(s) + 1);
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoingn(char *s, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
	{
		s = ft_calloc(sizeof(char), 1);
		s[0] = '\0';
	}
	s3 = ft_calloc(sizeof(char), ft_strl(s) + ft_strl(s2) + 2);
	if (!s3)
		return (NULL);
	while (s[++i])
		s3[i] = s[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s);
	return (s3);
}

char	*ft_strchrgn(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c < 0)
		return (s);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_new_line(char *s)
{
	char	*line;
	int		i;

	if (!s)
		return (free(s), NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i] = s[i];
	i++;
	line[i] = '\0';
	return (line);
}
