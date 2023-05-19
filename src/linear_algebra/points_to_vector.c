/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:54 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 21:43:47 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vector	vector_p1_p2(t_point p1, t_point p2)
{
	t_vector	res;

	res.x = p2.x - p1.x;
	res.y = p2.y - p1.y;
	res.z = p2.z - p1.z;
	return (res);
}

t_vector	vector_0_p(t_point p)
{
	t_vector	res;

	res.x = p.x;
	res.y = p.y;
	res.z = p.z;
	return (res);
}

t_vector	vector_p_0(t_point p)
{
	t_vector	res;

	res.x = -1 * p.x;
	res.y = -1 * p.y;
	res.z = -1 * p.z;
	return (res);
}

t_point	scalaire(t_vector ray, double scalare)
{
	t_point	m;

	m.x = ray.x * scalare;
	m.y = ray.y * scalare;
	m.z = ray.z * scalare;
	return (m);
}
