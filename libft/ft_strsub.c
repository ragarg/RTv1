/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:51:22 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 14:58:34 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char *s, unsigned int start, size_t len)
{
	char *n_s;

	n_s = ft_strnew(len);
	if (!s || !n_s)
		return (NULL);
	ft_strncpy(n_s, s + start, len);
	return (n_s);
}
