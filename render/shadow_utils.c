/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:05:12 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 15:05:48 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

static int	get_ray_light(t_data data, t_vector ray, double t, t_point origin)
{
	t_vector	ray_light;
	t_point		p;
	double		dot;

	p = scalaire(ray, t);
	add__point_to_reference_(&p, origin);
	ray_light = vector_p1_p2(p, data.light->point);
	normalize(&ray_light);
	dot = dot_v_v(ray_light, ray);
	if (dot < 0)
		return (0);
	return (1);
}

static int	get_solution_shadow(t_data data, t_vector ray,
	t_point origin, t_solution *s)
{
	t_solution	*arr_t[3];
	t_solution	*temp;

	arr_t[0] = plane_rendering_shadow(data, ray, origin, s);
	arr_t[1] = sphere_rendering_shadow(data, ray, origin, s);
	arr_t[2] = cylinder_rendering_shadow(data, ray, origin, s);
	temp = get_min(arr_t);
	if (temp)
	{
		if (temp->solution == true)
		{
			if (get_ray_light(data, ray, temp->t, origin))
			{
				free(temp);
				return (1);
			}
		}
		free(temp);
	}
	return (0);
}

int	shadow_rending(t_data data, t_solution *s, t_vector ray)
{
	t_vector	shadow_ray;
	t_point		p;

	if (s && s->t != DBL_MAX)
	{
		p = scalaire(ray, s->t);
		shadow_ray = vector_p1_p2(p, data.light->point);
		normalize(&shadow_ray);
		if (get_solution_shadow(data, shadow_ray, p, s))
			return (1);
	}
	return (0);
}
