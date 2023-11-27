/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:28:59 by jchakir           #+#    #+#             */
/*   Updated: 2022/06/08 20:01:08 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

void	normalize(t_vector *vector)
{
	double	len;

	len = norm(*vector);
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
}

t_vector	get_normalized_vector(t_vector orig)
{
	t_vector	vector;
	double		len;

	len = norm(orig);
	vector.x = orig.x / len;
	vector.y = orig.y / len;
	vector.z = orig.z / len;
	return (vector);
}
