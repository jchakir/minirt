/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product_vectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:36 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/06 19:32:15 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

double	dot_v_v(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	dot_p_p(t_point p1, t_point p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

double	dot_v_p(t_vector v, t_point p)
{
	return (v.x * p.x + v.y * p.y + v.z * p.z);
}
