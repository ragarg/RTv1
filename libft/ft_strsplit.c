/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:13:23 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 15:25:44 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char const *str, char c)
{
	int count;
	int	n;

	n = 0;
	count = 0;
	while (str[n])
	{
		while (str[n] == c)
			n++;
		if (str[n] != c && str[n] != '\0')
			count++;
		while (str[n] != c && str[n] != '\0')
			n++;
	}
	return (count);
}

static int		get_word_len(char const *str, char c)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	while (str[n] == c)
		n++;
	while (str[n] != c && str[n] != '\0')
	{
		n++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**n_s;
	int		len;

	if (!s)
		return (NULL);
	len = countwords(s, c);
	if (!(n_s = (char **)malloc(sizeof(*n_s) * (len + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len)
	{
		k = 0;
		n_s[i] = ft_strnew(get_word_len(&s[j], c) + 1);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			n_s[i][k++] = s[j++];
		n_s[i][k] = '\0';
	}
	n_s[i] = 0;
	return (n_s);
}
