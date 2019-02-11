/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:41:20 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 15:42:36 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				k;
	char			*uns;
	int				len;
	unsigned int	num;

	k = 0;
	num = n;
	if (n < 0)
	{
		num = -1 * n;
		k++;
	}
	len = len_int(num) + k;
	if (!(uns = ft_strnew(len)))
		return (NULL);
	uns[--len] = num % 10 + '0';
	while (num /= 10)
		uns[--len] = num % 10 + '0';
	if (k == 1)
		uns[--len] = '-';
	return (uns);
}
