/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:55:01 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 11:55:03 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *destptr, const char *srcptr, size_t num)
{
	size_t n;

	n = 0;
	while (srcptr[n] && num > n)
	{
		destptr[n] = srcptr[n];
		n++;
	}
	while (num > n)
		destptr[n++] = 0;
	return (destptr);
}
