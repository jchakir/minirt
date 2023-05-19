/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_inverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:39 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 13:13:03 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

static t_matrix3x3	get_transpose_matrix3x3(t_matrix3x3 orig)
{
	t_matrix3x3	res;
	t_vector	u;
	t_vector	v;
	t_vector	w;

	u.x = orig.u[0];
	u.y = orig.v[0];
	u.z = orig.w[0];
	v.x = orig.u[1];
	v.y = orig.v[1];
	v.z = orig.w[1];
	w.x = orig.u[2];
	w.y = orig.v[2];
	w.z = orig.w[2];
	res = set_matrix(u, v, w);
	return (res);
}

static void	adjugate_this_matrix3x3(t_matrix3x3 *m)
{
	t_vector	u;
	t_vector	v;
	t_vector	w;

	u.x = m->v[1] * m->w[2] - m->v[2] * m->w[1];
	u.y = m->v[0] * m->w[2] - m->v[2] * m->w[0];
	u.z = m->v[0] * m->w[1] - m->v[1] * m->w[0];
	v.x = m->u[1] * m->w[2] - m->u[2] * m->w[1];
	v.y = m->u[0] * m->w[2] - m->u[2] * m->w[0];
	v.z = m->u[0] * m->w[1] - m->u[1] * m->w[0];
	w.x = m->u[1] * m->v[2] - m->u[2] * m->v[1];
	w.y = m->u[0] * m->v[2] - m->u[2] * m->v[0];
	w.z = m->u[0] * m->v[1] - m->u[1] * m->v[0];
	u.y = u.y * -1;
	v.x = v.x * -1;
	v.z = v.z * -1;
	w.y = w.y * -1;
	*m = set_matrix(u, v, w);
}

static void	multiply_num_to_matrix3x3(double num, t_matrix3x3 *m)
{
	m->u[0] *= num;
	m->u[1] *= num;
	m->u[2] *= num;
	m->v[0] *= num;
	m->v[1] *= num;
	m->v[2] *= num;
	m->w[0] *= num;
	m->w[1] *= num;
	m->w[2] *= num;
}

static double	get_determinant_of_matrix3x3__det_3x3_(t_matrix3x3 m)
{
	double	det1;
	double	det2;
	double	det3;

	det1 = m.v[1] * m.w[2] - m.v[2] * m.w[1];
	det2 = m.v[0] * m.w[2] - m.v[2] * m.w[0];
	det3 = m.v[0] * m.w[1] - m.v[1] * m.w[0];
	return (m.u[0] * det1 - m.u[1] * det2 + m.u[2] * det3);
}

t_matrix3x3	get_matrix_inverse(t_matrix3x3 origin)
{
	t_matrix3x3	m_inverse;
	double		det;

	m_inverse = get_transpose_matrix3x3(origin);
	adjugate_this_matrix3x3(&m_inverse);
	det = get_determinant_of_matrix3x3__det_3x3_(origin);
	if (det == 0)
		return (m_inverse);
	multiply_num_to_matrix3x3(1 / det, &m_inverse);
	return (m_inverse);
}
