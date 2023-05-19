/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_render_shadow.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:29:19 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 14:14:56 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

int	check_point_outside(t_data data, t_vector ray, t_point origin)
{
	t_point	p;
	double	dot;

	dot = dot_v_v(vector_p1_p2(data.cylinder->point, origin),
			data.cylinder->vector);
	p = scalaire(data.cylinder->vector, dot);
	add__point_to_reference_(&p, data.cylinder->point);
	dot = dot_v_v(get_normalized_vector(vector_p1_p2(origin, p)), ray);
	if (dot >= 0)
		return (0);
	return (1);
}

int	check_point_outside_tocam(t_data data, t_point origin)
{
	t_point	p;
	double	dot;

	dot = dot_v_v(vector_p1_p2(data.cylinder->point, origin),
			data.cylinder->vector);
	p = scalaire(data.cylinder->vector, dot);
	add__point_to_reference_(&p, data.cylinder->point);
	dot = dot_v_v(vector_p1_p2(origin, p),
			vector_p1_p2(origin, data.camera->point));
	if (dot >= 0)
		return (0);
	return (1);
}

double	cylinder_q4_equation2(t_data data, t_vector ray,
	t_point origin)
{
	t_quadratic	q;
	t_point		p;
	double		max;
	double		x;

	if (check_point_outside(data, ray, origin)
		|| check_point_outside_tocam(data, origin))
		return (0);
	if (!get_solutions(data, ray, origin, &q))
		return (0);
	if (q.x2 < 0)
		return (0);
	if (q.x1 > 0)
		x = q.x1;
	else
		x = q.x2;
	max = sqrt(pow(data.cylinder->height / 2, 2) + pow(q.r, 2));
	p = get_p(data, origin, ray, x);
	if (norm_p(p) <= max)
		x = q.x2;
	p = get_p(data, origin, ray, x);
	if (norm_p(p) <= max)
		return (ft_max(q.x1, q.x2));
	return (0);
}

t_solution	*cylinder_rendering_shadow(t_data data, t_vector ray,
	t_point origin, t_solution *sol)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	while (data.cylinder)
	{
		if (sol->type == CYLINDER && sol->id == i)
		{
			if (cylinder_q4_equation2(data, ray, origin))
				add_s_back(&s, s_filling_cylinder(data, ray, i, origin));
		}
		else
		{
			if (cylinder_q4_equation(data, ray, origin))
				add_s_back(&s, s_filling_cylinder(data, ray, i, origin));
		}
		i++;
		data.cylinder = data.cylinder->next;
	}
	return (get_min_ll(s));
}
