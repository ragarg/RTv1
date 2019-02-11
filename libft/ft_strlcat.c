/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srrlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:04:12 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:04:59 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libft.h"

size_t		ft_strlcat(char *destptr, const char *srcptr, size_t num)
{
	size_t		dst_len;
	size_t		src_len;

	dst_len = ft_strlen(destptr);
	src_len = ft_strlen(srcptr);
	if (num < dst_len + 1)
		return (src_len + num);
	ft_strncat(destptr, srcptr, num);
	destptr[num - 1] = 0;
	return (dst_len + src_len);
}
