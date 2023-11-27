/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:52 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 19:59:02 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

double	norm(t_vector vector)
{
	return (sqrt(dot_v_v(vector, vector)));
}

double	norm_p(t_point point)
{
	return (sqrt(dot_p_p(point, point)));
}

double	norm_0_p(t_point p)
{
	return (sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2)));
}

double	norm_p1_p2(t_point p1, t_point p2)
{
	double	x;
	double	y;
	double	z;

	x = p2.x - p1.x;
	y = p2.y - p1.y;
	z = p2.z - p1.z;
	return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

t_vector	get_reversed_vector(t_vector orig)
{
	t_vector	v;

	v.x = -1 * orig.x;
	v.y = -1 * orig.y;
	v.z = -1 * orig.z;
	return (v);
}
