/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cam_world.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:35:24 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 22:52:29 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

void	transform_points(t_data data, t_matrix3x3 m)
{
	matrix3x3_multiply_to_point(&data.light->point, m);
	while (data.plane)
	{
		matrix3x3_multiply_to_point(&data.plane->point, m);
		data.plane = data.plane->next;
	}
	while (data.sphere)
	{
		matrix3x3_multiply_to_point(&data.sphere->point, m);
		data.sphere = data.sphere->next;
	}
	while (data.cylinder)
	{
		matrix3x3_multiply_to_point(&data.cylinder->point, m);
		data.cylinder = data.cylinder->next;
	}
}

void	transform_vectors(t_data data, t_matrix3x3 m)
{
	matrix3x3_multiply_to_vector(&data.camera->vector, m);
	while (data.plane)
	{
		matrix3x3_multiply_to_vector(&data.plane->vector, m);
		data.plane = data.plane->next;
	}
	while (data.cylinder)
	{
		matrix3x3_multiply_to_vector(&data.cylinder->vector, m);
		data.cylinder = data.cylinder->next;
	}
}

void	translate_all_coords(t_data data)
{
	subtract__point_reference_(&data.light->point, data.camera->point);
	while (data.plane)
	{
		subtract__point_reference_(&data.plane->point, data.camera->point);
		data.plane = data.plane->next;
	}
	while (data.sphere)
	{
		subtract__point_reference_(&data.sphere->point, data.camera->point);
		data.sphere = data.sphere->next;
	}
	while (data.cylinder)
	{
		subtract__point_reference_(&data.cylinder->point, data.camera->point);
		data.cylinder = data.cylinder->next;
	}
	subtract__point_reference_(&data.camera->point, data.camera->point);
}

void	transform_cam_world(t_data data)
{
	t_matrix3x3	m;

	translate_all_coords(data);
	m = get_transform_matrix(data.camera->vector);
	transform_vectors(data, m);
	transform_points(data, m);
}
