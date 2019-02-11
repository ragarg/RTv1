/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:13 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 14:36:47 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int	n;
	char			*n_s;

	n = 0;
	if (!s || !f)
		return (NULL);
	n_s = ft_strnew(ft_strlen(s));
	if (!n_s)
		return (NULL);
	while (s[n])
	{
		n_s[n] = f(s[n]);
		n++;
	}
	n_s[n] = 0;
	return (n_s);
}
