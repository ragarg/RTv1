/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:02:22 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:02:51 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *destptr, const char *srcptr, size_t num)
{
	size_t n;
	size_t k;

	n = 0;
	k = 0;
	while (destptr[n])
		n++;
	while (srcptr[k] && num > k)
		destptr[n++] = srcptr[k++];
	destptr[n] = '\0';
	return (destptr);
}
