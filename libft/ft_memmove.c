/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:17:29 by apaghera          #+#    #+#             */
/*   Updated: 2022/11/03 12:59:27 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	else
	{
		if (d > s)
			while (len-- > 0)
				d[len] = s[len];
		else
		{
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		}
		return (dst);
	}
}
