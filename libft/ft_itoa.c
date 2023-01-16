/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:25:08 by apaghera          #+#    #+#             */
/*   Updated: 2022/11/03 11:37:16 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int nb)
{
	int	count;
	int	res;

	count = 0;
	res = nb;
	if (nb == 0)
		count = 1;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (res != 0)
	{
		res = nb / 10;
		nb = nb / 10;
		count ++;
	}
	return (count);
}

static char	*ft_num(long int n)
{
	char	*num;
	size_t	count;
	int		j;

	count = ft_count(n);
	j = count;
	num = malloc(sizeof(char) * count + 1);
	if (!num)
		return (NULL);
	num[j--] = '\0';
	if (n == 0)
		num[0] = n + '0';
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		num[j] = '0' + n % 10;
		n = n / 10;
		j--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;

	num = ft_num(n);
	return (num);
}
