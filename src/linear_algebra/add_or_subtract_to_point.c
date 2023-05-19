/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_or_subtract_to_point.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:27 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/04 15:12:47 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

void	subtract__point_reference_(t_point *point, t_point reference)
{
	point->x -= reference.x;
	point->y -= reference.y;
	point->z -= reference.z;
}

void	add__point_to_reference_(t_point *point, t_point reference)
{
	point->x += reference.x;
	point->y += reference.y;
	point->z += reference.z;
}
