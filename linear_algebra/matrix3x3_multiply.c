/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3x3_multiply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:50 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 19:59:55 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

void	matrix3x3_multiply_to_vector(t_vector *v, t_matrix3x3 m)
{
	double	x;
	double	y;
	double	z;

	x = m.u[0] * v->x + m.v[0] * v->y + m.w[0] * v->z;
	y = m.u[1] * v->x + m.v[1] * v->y + m.w[1] * v->z;
	z = m.u[2] * v->x + m.v[2] * v->y + m.w[2] * v->z;
	v->x = x;
	v->y = y;
	v->z = z;
}

void	matrix3x3_multiply_to_point(t_point *p, t_matrix3x3 m)
{
	double	x;
	double	y;
	double	z;

	x = m.u[0] * p->x + m.v[0] * p->y + m.w[0] * p->z;
	y = m.u[1] * p->x + m.v[1] * p->y + m.w[1] * p->z;
	z = m.u[2] * p->x + m.v[2] * p->y + m.w[2] * p->z;
	p->x = x;
	p->y = y;
	p->z = z;
}
