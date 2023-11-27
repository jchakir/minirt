/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:27:30 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:25:54 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

double	plane_intersection(t_data data, t_vector ray, t_point origin)
{
	t_vector	n;
	double		t;
	double		denom;

	t = -1;
	n = get_normalized_vector(data.plane->vector);
	denom = dot_v_v(ray, n);
	if (fabs(denom) > 1e-6)
	{
		t = dot_v_v(vector_p1_p2(origin, data.plane->point), n) / denom;
		if (t >= 0)
			return (t);
	}
	return (-1);
}

double	plane_ratio(t_data data, t_vector ray, double t)
{
	t_point		m;
	t_vector	ml;
	t_vector	n;
	double		dotprod;

	m = scalaire(ray, t);
	n = get_normalized_vector(data.plane->vector);
	ml = vector_p1_p2(m, data.light->point);
	normalize(&ml);
	dotprod = dot_v_v(ml, n);
	return (fabs(dotprod));
}

t_solution	*s_filling_plane(t_data data, t_vector ray, int id, t_point origin)
{
	t_solution	*s;
	double		ratio_color;

	s = malloc(sizeof(t_solution));
	if (!s)
		return (NULL);
	s->solution = true;
	s->type = PLANE;
	s->id = id;
	s->t = plane_intersection(data, ray, origin);
	s->rgb = data.plane->rgb;
	ratio_color = plane_ratio(data, ray, s->t);
	s->color = create_trgb(0, data.plane->rgb, ratio_color, data.light->ratio);
	s->next = NULL;
	return (s);
}

t_solution	*plane_rendering(t_data data, t_vector ray, t_point origin)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	if (data.plane)
	{
		while (data.plane)
		{
			if (plane_intersection(data, ray, origin) >= 0)
				add_s_back(&s, s_filling_plane(data, ray, i, origin));
			i++;
			data.plane = data.plane->next;
		}
	}
	return (get_min_ll(s));
}
