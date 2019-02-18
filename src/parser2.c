/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:34:16 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 16:06:05 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

void	l_real(t_param *p)
{
	int			i;
	t_light		*new;

	++p->l_count;
	new = (t_light *)malloc(sizeof(t_light) * p->l_count);
	i = -1;
	while (++i < p->l_count - 1)
		new[i] = p->l[i];
	if (p->l)
		free(p->l);
	p->l = new;
}

void	sp_real(t_param *p)
{
	int			i;
	t_sphere	*new;

	++p->sp_count;
	new = (t_sphere *)malloc(sizeof(t_sphere) * p->sp_count);
	i = -1;
	while (++i < p->sp_count - 1)
		new[i] = p->sp[i];
	if (p->sp)
		free(p->sp);
	p->sp = new;
}
