/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_render_shadow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:29:28 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:50:22 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

t_solution	*sphere_rendering_shadow(t_data data, t_vector ray,
	t_point origin, t_solution *sol)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	while (data.sphere)
	{
		if (sphere_q4_equation(data, ray, origin))
			add_s_back(&s, s_filling_sphere(data, ray, i, origin));
		i++;
		data.sphere = data.sphere->next;
	}
	return (get_min_ll_shadow(s, sol));
}
