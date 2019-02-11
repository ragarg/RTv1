/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:17:31 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 16:18:00 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	int n;

	if (!s)
		return ;
	n = 0;
	while (s[n])
		ft_putchar_fd(s[n++], fd);
}