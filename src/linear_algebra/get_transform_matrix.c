/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_transform_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:42 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 22:52:06 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_matrix3x3	set_matrix(t_vector u, t_vector v, t_vector w)
{
	t_matrix3x3	m;

	m.u[0] = u.x;
	m.u[1] = u.y;
	m.u[2] = u.z;
	m.v[0] = v.x;
	m.v[1] = v.y;
	m.v[2] = v.z;
	m.w[0] = w.x;
	m.w[1] = w.y;
	m.w[2] = w.z;
	return (m);
}

static t_vector	get_vector__vx_(t_vector vz)
{
	t_vector	j;
	t_vector	vx;

	vx.z = 0;
	vx.y = 0;
	if (vz.y == 1 || vz.y == -1)
	{
		vx.x = 1;
		return (vx);
	}
	j.x = 0;
	j.y = 1;
	j.z = 0;
	return (cross_2v(j, vz));
}

t_matrix3x3	get_transform_matrix(t_vector cam)
{
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;
	t_matrix3x3	m;

	vz = get_reversed_vector(cam);
	vx = get_vector__vx_(vz);
	vy = cross_2v(vz, vx);
	m = set_matrix(vx, vy, vz);
	return (get_matrix_inverse(m));
}
