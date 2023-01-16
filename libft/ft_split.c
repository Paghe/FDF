/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:45:57 by apaghera          #+#    #+#             */
/*   Updated: 2022/12/27 20:50:25 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str)
			count++;
		while (*str != '\0' && *str != c)
			str++;
	}
	return (count);
}

static int	ft_size_word(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != c)
		count++;
	return (count);
}

static char	*ft_dup_word(const char *str, int size)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	while (i < size)
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s1 = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!s1)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			s1[i] = ft_dup_word(s, ft_size_word(s, c));
			if (!s1[i])
				return (ft_free(s1, i));
			s += ft_size_word(s, c);
			i++;
		}
	}
	s1[i] = NULL;
	return (s1);
}
