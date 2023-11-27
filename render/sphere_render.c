/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:27:35 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 15:16:52 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

double	sphere_q4_equation(t_data data, t_vector ray, t_point origin)
{
	t_vector	p;
	t_quadratic	q;

	p = vector_p1_p2(data.sphere->point, origin);
	q.r = data.sphere->diameter / 2;
	q.a = 1;
	q.b = 2 * dot_v_v(ray, p);
	q.c = dot_v_v(p, p) - pow(q.r, 2);
	q.delta = pow(q.b, 2) - (4 * q.a * q.c);
	if (q.delta > 0)
	{
		q.x1 = (-q.b - sqrt(q.delta)) / (2 * q.a);
		q.x2 = (-q.b + sqrt(q.delta)) / (2 * q.a);
		if (ft_min(q.x1, q.x2) >= 0)
			return (ft_min(q.x1, q.x2));
	}
	else if (q.delta == 0)
		return (ft_max(-q.b / 2 * q.a, 0));
	return (0);
}

double	sphere_ratio(t_data data, t_vector ray, double t)
{
	t_point		m;
	t_vector	ml;
	t_vector	n;

	m = scalaire(ray, t);
	ml = vector_p1_p2(m, data.light->point);
	normalize(&ml);
	n = vector_p1_p2(data.sphere->point, m);
	normalize(&n);
	return (fabs(ft_min(dot_v_v(ml, n), 0)));
}

t_solution	*s_filling_sphere(t_data data, t_vector ray, int id, t_point origin)
{
	t_solution	*s;
	double		ratio_color;

	s = malloc(sizeof(t_solution));
	if (!s)
		return (NULL);
	s->solution = true;
	s->type = SPHERE;
	s->id = id;
	s->t = sphere_q4_equation(data, ray, origin);
	s->rgb = data.sphere->rgb;
	ratio_color = sphere_ratio(data, ray, s->t);
	s->color = create_trgb(0, data.sphere->rgb,
			1 - ratio_color, data.light->ratio);
	s->next = NULL;
	return (s);
}

t_solution	*sphere_rendering(t_data data, t_vector ray, t_point origin)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	if (data.sphere)
	{
		while (data.sphere)
		{
			if (sphere_q4_equation(data, ray, origin))
				add_s_back(&s, s_filling_sphere(data, ray, i, origin));
			i++;
			data.sphere = data.sphere->next;
		}
	}
	return (get_min_ll(s));
}
