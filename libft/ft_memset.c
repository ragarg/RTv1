/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:38:26 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 13:38:28 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dest, int c, size_t num)
{
	char	*ptr;
	size_t	n;

	ptr = (char*)dest;
	n = 0;
	while (n < num)
		*(ptr + n++) = c;
	return (dest);
}
