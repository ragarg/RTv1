/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:28:12 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/05 22:55:05 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		trace_sphere(t_sphere s, t_point cam, t_point p)
{
	int		k1;
	int		k2;
	int		k3;
	t_vec	d;
	t_vec	oc;
	int		disc;

	d = vec_frompoint(cam, p);
	oc = vec_frompoint(cam, s.cen);
	if (sqrt(vec_scal(oc, oc)) <= s.rad)
		return (1);
	else
		return (0);
	k1 = vec_scal(d, d);
	k2 = 2 * vec_scal(oc, d);
	k3 = vec_scal(oc, oc) - s.rad * s.rad;
//	printf("%d  %d  %d\n", k1, k2, k3);
	disc = k2 * k2 - 4 * k1 * k3;
	if (disc > 0)
		return (1);
	return (0);
}
