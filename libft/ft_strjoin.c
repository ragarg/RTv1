/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:59:30 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 15:02:15 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	n;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new_str)
		return (NULL);
	n = -1;
	k = -1;
	while (s1[++n])
		new_str[n] = s1[n];
	while (s2[++k])
		new_str[n++] = s2[k];
	return (new_str);
}
