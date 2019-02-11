/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:03:40 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/05 21:32:31 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		vec_frompoint(t_point p1, t_point p2)
{
	t_vec	res;

	res.i = p2.x - p1.x;
	res.j = p2.y - p1.y;
	res.k = p2.z - p1.z;
	return (res);
}

t_vec		vec_sum(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.i = v1.i + v2.i;
	res.i = v1.j + v2.j;
	res.i = v1.k + v2.k;
	return (res);
}

t_vec		vec_multi(int a, t_vec res)
{
	res.i *= a;
	res.j *= a;
	res.k *= a;
	return (res);
}

double			vec_scal(t_vec v1, t_vec v2)
{
	return (v1.i * v2.i + v1.j * v2.j + v1.k * v2.k);
}

double			vec_len(t_vec v)
{
	return ((int)sqrt(v.i * v.i + v.j * v.j + v.k * v.k));
}
