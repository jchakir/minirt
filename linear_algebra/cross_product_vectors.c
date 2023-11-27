/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:32 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 20:02:27 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vector	cross_2v(t_vector u, t_vector v)
{
	t_vector	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
