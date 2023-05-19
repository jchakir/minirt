/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:27:06 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 21:28:23 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

int	get_solutions(t_data data, t_vector ray, t_point origin, t_quadratic *q)
{
	t_vector	new_ray;
	t_vector	c_to_o;

	q->r = data.cylinder->diameter / 2;
	normalize(&data.cylinder->vector);
	new_ray = cross_2v(ray, data.cylinder->vector);
	c_to_o = vector_p1_p2(data.cylinder->point, origin);
	q->a = dot_v_v(new_ray, new_ray);
	q->b = 2 * dot_v_v(new_ray, cross_2v(c_to_o, data.cylinder->vector));
	q->c = dot_v_v(cross_2v(c_to_o, data.cylinder->vector),
			cross_2v(c_to_o, data.cylinder->vector)) - pow(q->r, 2);
	q->delta = pow(q->b, 2) - (4 * q->a * q->c);
	if (q->delta < 0)
		return (0);
	q->x1 = (-q->b - sqrt(q->delta)) / (2 * q->a);
	q->x2 = (-q->b + sqrt(q->delta)) / (2 * q->a);
	return (1);
}

t_point	get_p(t_data data, t_point origin, t_vector ray, double x)
{
	t_point	p;
	t_point	cyl_axe;

	cyl_axe.x = data.cylinder->point.x
		+ (data.cylinder->height / 2) * data.cylinder->vector.x;
	cyl_axe.y = data.cylinder->point.y
		+ (data.cylinder->height / 2) * data.cylinder->vector.y;
	cyl_axe.z = data.cylinder->point.z
		+ (data.cylinder->height / 2) * data.cylinder->vector.z;
	p = scalaire(ray, x);
	add__point_to_reference_(&p, origin);
	subtract__point_reference_(&p, cyl_axe);
	return (p);
}
