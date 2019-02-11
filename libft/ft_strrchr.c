/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:08:20 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:08:42 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int		i;

	i = 0;
	while (string[i])
		i++;
	i++;
	while (i--)
	{
		if (*(string + i) == (char)symbol)
			return ((char *)string + i);
	}
	return (NULL);
}
