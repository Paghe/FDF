/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:55:46 by apaghera          #+#    #+#             */
/*   Updated: 2022/11/03 13:17:57 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*s2;
	size_t				count;
	size_t				i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && count < len)
		{
			s2[count++] = s[i];
		}
		i++;
	}	
	s2[count] = '\0';
	return (s2);
}
