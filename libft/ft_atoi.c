/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:40:26 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 13:45:43 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(long long int uns, long long int uns_c)
{
	if (uns > 0 && 0 > uns_c)
		return (0);
	if (uns < 0 && 0 < uns_c)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	size_t			n;
	char			f;
	long long int	uns;
	long long int	uns_c;

	n = 0;
	while ((str[n] == '\n' || str[n] == '\t' || str[n] == '\r'
			|| str[n] == '\v' || str[n] == '\f' || str[n] == ' '))
		n++;
	f = str[n] == '-' ? -1 : 1;
	if (str[n] == '-' || str[n] == '+')
		n++;
	uns = 0;
	while (str[n] == 48)
		n++;
	while (ft_isdigit(str[n]))
	{
		uns_c = uns;
		uns *= 10;
		uns += (str[n] - 48) * f;
		if (check(uns, uns_c) != 1)
			return (check(uns, uns_c));
		n++;
	}
	return ((int)uns);
}
