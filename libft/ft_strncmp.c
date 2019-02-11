/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:25:39 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:27:27 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t n;

	n = 0;
	while (num > n && string1[n] == string2[n] && string1[n])
	{
		n++;
	}
	if (num == n)
		return (0);
	return ((unsigned char)string1[n] - (unsigned char)string2[n]);
}
