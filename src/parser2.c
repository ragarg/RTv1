/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:34:16 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/19 11:59:16 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char			*get_word(char *line)
{
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		*line++ = '\0';
	return (line);
}

double	get_double(char *line)
{
	unsigned long	full;
	double			num;
	double			prec;
	int				sign;

//	printf("%s\n", line);
	sign = 0;
	full = 0;
	if (*line == '-')
	{
		line++;
		sign = 1;
	}
	while (ft_isdigit(*line))
		if ((full = full * 10 + *line++ - '0') > 1000000)
			STOP;
	num = full * 1.0;
	if (*line++ != '.')
		STOP;
	prec = 0.1;
	while (ft_isdigit(*line))
	{
		if (prec < 0.0001)
			STOP;
		num += (*line++ - '0') * prec;
		prec *= 0.1;
	}
	if (*line != '\0' && *line != ',' && *line != ')')
		STOP;
	return (sign ? num * -1.0 : num);
}

t_vec	get_vec(char *line)
{
	t_vec	new;
	char	*num2;
	char	*num3;

//	printf("%s\n", line);
	if (*line++ != '(')
		STOP;
	num2 = get_word(line);
	num3 = get_word(num2);
	new.x = get_double(line);
	new.y = get_double(num2);
	new.z = get_double(num3);
	return (new);
}

