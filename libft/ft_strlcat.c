/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:45:18 by apaghera          #+#    #+#             */
/*   Updated: 2022/11/03 13:22:47 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(const char *str)
{
	int	i;

	i = 0;
	if (!str || *str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	res;

	i = 0;
	res = 0;
	len_dst = ft_strlen1(dst);
	len_src = ft_strlen1(src);
	if (!dstsize)
		return (len_src);
	if (dstsize > len_dst)
		res = len_dst + len_src;
	else
		res = dstsize + len_src;
	while (src[i] != '\0' && len_dst + 1 < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
}
