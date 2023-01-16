/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:10:37 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/14 16:13:46 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "stdio.h"
#include <stdlib.h>

/* int	ft_count_wordfdf(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if ((*str != c && *(str + 1) == c) || *(str + 1) == '\0')
			count++;
		str++;
	}
	return (count);
}
 */
int	get_height(char *path)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	height = 0;
	while (line)
	{
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *path)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	width = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = ft_count_word(line, ' ');
	if (!width)
		return (0);
	free(line);
	close(fd);
	return (width);
}

int	get_len(char *path)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

/* char	**get_map(char *path)
{
	int		fd;
	char	**split;
	char	*line;
	char	*res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * LINE_MAX);
	res = malloc(sizeof(char) * get_len(path) + 1);
	if (!line || !res)
		return (NULL);
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != 0)
	{
		res = ft_strjoin(res, line);
		res = ft_strjoin(res, " ");
		line = get_next_line(fd);
	}
	printf("res: %s:\n", res);
	split = ft_split(res, ' '); //declare '\0'
	printf("split: %s:\n", split[19]);
	free(line);
	free(res);
	close(fd);
	return (split);
} */

char	**get_map(char *path)
{
	int		fd;
	char	**split;
	char	*line;
	char	*res;

	fd = open(path, O_RDONLY);
	line = ft_calloc(sizeof(char), get_width(path) + 1);
	res = ft_calloc(sizeof(char), get_len(path) + 1);
	line = get_next_line(fd);
	while (line && res)
	{
		res = ft_strjoin(res, " ");
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
	}
	split = ft_split(res, ' ');
	if (!split)
	{
		free(split);
		free(*split);
		return (NULL);
	}
	free(line);
	close(fd);
	return (split);
}

void	get_matrix(char *path, t_point *point)
{
	int		i;
	char	**split;
	int		j;

	i = 0;
	point -> height = get_height(path);
	point -> width = get_width(path);
	point -> z = (int **)ft_calloc(sizeof(int *), (point -> height + 1));
	while (i <= point -> height)
		point -> z[i++] = (int *)ft_calloc(sizeof(int), (point -> width + 1));
	if (!point -> z)
		point -> z = NULL;
	split = get_map(path);
	*split = ft_strjoin(*split, " ");
	i = -1;
	while (++i < point -> height)
	{
		j = 0;
		while (j < point -> width && *split)
			point -> z[i][j++] = ft_atoi(*split++);
	}
	point->z[i] = NULL;
	i = 0;
	free_mem(split);
}
