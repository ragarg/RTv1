/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:52:33 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 11:54:49 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *destptr, const char *srcptr)
{
	int		len;

	len = ft_strlen(srcptr);
	ft_strncpy(destptr, srcptr, len);
	destptr[len] = 0;
	return (destptr);
}
