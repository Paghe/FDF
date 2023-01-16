/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:10:06 by apaghera          #+#    #+#             */
/*   Updated: 2022/12/14 19:26:09 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (size && total / size != count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*get_read_line(int fd, char *stash)
{
	char			*buff;
	int				i;

	i = 1;
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (free(stash), NULL);
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		if (!stash)
			stash = ft_strdupgn(buff);
		else
			stash = ft_strjoingn(stash, buff);
		if (ft_strchrgn(stash, '\n') != 0)
			i = 0;
	}
	free(buff);
	return (stash);
}

char	*next_line(char *stash)
{
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n' && ft_strl(stash) > 1 && stash[i + 1])
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	cpy = ft_calloc(sizeof(char), ft_strl(stash) - i + 1);
	if (!cpy)
		return (NULL);
	i++;
	while (stash[i])
		cpy[j++] = stash[i++];
	cpy[j] = '\0';
	free(stash);
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_read_line(fd, stash);
	if (!stash)
		return (free(stash), NULL);
	line = ft_new_line(stash);
	if (!line)
		return (free(stash), NULL);
	stash = next_line(stash);
	if (!stash)
		return (free(line), NULL);
	return (line);
}
