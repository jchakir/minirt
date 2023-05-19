/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_render_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:28:25 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:50:33 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

t_solution	*plane_rendering_shadow(t_data data, t_vector ray,
	t_point origin, t_solution *sol)
{
	t_solution	*s;
	int			i;

	i = 1;
	s = NULL;
	while (data.plane)
	{
		if (plane_intersection(data, ray, origin) >= 0)
			add_s_back(&s, s_filling_plane(data, ray, i, origin));
		i++;
		data.plane = data.plane->next;
	}
	return (get_min_ll_shadow(s, sol));
}
