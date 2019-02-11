/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:17:22 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:18:16 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string1, const char *string2, size_t num)
{
	size_t n;
	size_t k;

	if (!string2[0])
		return ((char *)string1);
	n = 0;
	if (!ft_strlen(string2))
		return ((char *)string1);
	while (string1[n] && n < num)
	{
		if (string1[n] == string2[0])
		{
			k = 0;
			while (string1[n + k] == string2[k] && string2[k] && n + k < num)
				k++;
			if (!string2[k])
				return ((char*)(string1 + n));
		}
		n++;
	}
	return (NULL);
}
