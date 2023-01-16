/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:47:36 by apaghera          #+#    #+#             */
/*   Updated: 2022/11/03 13:01:06 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			j;
	unsigned char	*ptr;

	j = 0;
	ptr = (unsigned char *) b;
	while (j < len)
	{
		ptr[j] = (unsigned char) c;
		j++;
	}
	return (b);
}
