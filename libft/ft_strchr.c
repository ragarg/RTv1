/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:05:51 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 12:08:13 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	size_t	n;
	char	*s;

	s = (char*)string;
	n = 0;
	while (s[n] != symbol && s[n])
		n++;
	if (s[n] == symbol)
		return (s + n);
	else
		return (NULL);
}
