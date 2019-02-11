/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:05:17 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 15:12:33 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		n;
	int		len_s;
	int		k;
	char	*n_s;

	if (!s)
		return (NULL);
	n = 0;
	len_s = ft_strlen(s);
	k = 0;
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n++;
	len_s--;
	while (len_s != -1 && (s[len_s] == ' '
						|| s[len_s] == '\t' || s[len_s] == '\n'))
		len_s--;
	if (len_s == -1)
		return (ft_strnew(1));
	n_s = ft_strndup((char*)(s + n), len_s - n + 1);
	if (!n_s)
		return (NULL);
	n_s[len_s + 1] = 0;
	return (n_s);
}
