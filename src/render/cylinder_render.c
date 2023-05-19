/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:27:32 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:51:00 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

double	cylinder_q4_equation(t_data data, t_vector ray, t_point origin)
{
	t_quadratic	q;
	t_point		p;
	double		max;
	double		x;

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
		return (x);
	x = q.x2;
	p = get_p(data, origin, ray, x);
	if (norm_p(p) <= max)
		return (x);
	return (0);
}

double	cylinder_ratio(t_data data, t_vector ray, double t)
{
	t_point		m;
	t_point		center;
	t_vector	ml;
	t_vector	n;
	double		x;

	m = scalaire(ray, t);
	x = (-2 * dot_v_v(vector_p1_p2(m, data.cylinder->point),
				get_normalized_vector(data.cylinder->vector))) / 2;
	center = scalaire(data.cylinder->vector, x);
	add__point_to_reference_(&center, data.cylinder->point);
	n = vector_p1_p2(m, center);
	normalize(&n);
	ml = vector_p1_p2(m, data.light->point);
	normalize(&ml);
	if (dot_v_v(get_reversed_vector(ray), n) > 0 && dot_v_v(ml, n) > 0)
		return (ft_max(dot_v_v(ml, n), 0));
	else if (dot_v_v(get_reversed_vector(ray), n) < 0 && dot_v_v(ml, n) < 0)
		return (fabs(ft_min(dot_v_v(ml, n), 0)));
	return (0);
}

t_solution	*s_filling_cylinder(t_data data, t_vector ray,
	int id, t_point origin)
{
	t_solution	*s;
	double		ratio_color;

	s = malloc(sizeof(t_solution));
	if (!s)
		return (NULL);
	s->solution = true;
	s->type = CYLINDER;
	s->id = id;
	s->t = cylinder_q4_equation(data, ray, origin);
	s->rgb = data.cylinder->rgb;
	ratio_color = cylinder_ratio(data, ray, s->t);
	if (ratio_color < 0.15)
		s->color = create_trgb(TRANSPARENCY, data.amb_light->rgb,
				data.amb_light->ratio, 1);
	else
		s->color = create_trgb(0, data.cylinder->rgb,
				ratio_color, data.light->ratio);
	s->next = NULL;
	return (s);
}

t_solution	*cylinder_rendering(t_data data, t_vector ray, t_point origin)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	if (data.cylinder)
	{
		while (data.cylinder)
		{
			if (cylinder_q4_equation(data, ray, origin))
				add_s_back(&s, s_filling_cylinder(data, ray, i, origin));
			i++;
			data.cylinder = data.cylinder->next;
		}
	}
	return (get_min_ll(s));
}
