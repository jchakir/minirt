/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:31:46 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:52:50 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

void	get_pixel_coord(int x, int y, t_vector *ray, t_data data)
{
	double	tan_fov_asp_ratio;

	tan_fov_asp_ratio = data.tanfov * data.aspect_ratio;
	ray->x = (2 * ((x + 0.5) / IMAGE_WIDTH) - 1) * tan_fov_asp_ratio;
	ray->y = (1 - 2 * ((y + 0.5) / IMAGE_HEIGHT)) * data.tanfov;
	ray->z = -1;
}

int	create_trgb(int t, t_rgb colors, double ratio_color, double ratio_light)
{
	int	red;
	int	green;
	int	blue;

	red = colors.red * ratio_color * ratio_light;
	green = colors.green * ratio_color * ratio_light;
	blue = colors.blue * ratio_color * ratio_light;
	return (t << 24 | red << 16 | green << 8 | blue);
}

t_solution	*get_min(t_solution **arrt)
{
	t_solution	*temp;
	t_solution	*temp2;
	double		min;
	int			i;

	i = 0;
	min = DBL_MAX;
	temp = NULL;
	while (i < 3)
	{
		if (arrt[i] && arrt[i]->t > 0 && arrt[i]->t < min)
		{
			temp = arrt[i];
			min = arrt[i]->t;
		}
		i++;
	}
	temp2 = copy_list(temp);
	free(arrt[0]);
	free(arrt[1]);
	free(arrt[2]);
	return (temp2);
}

t_solution	*get_min_ll(t_solution *s)
{
	t_solution	*temp;
	t_solution	*temp2;
	t_solution	*temp3;
	double		min;

	temp = NULL;
	min = DBL_MAX;
	temp3 = s;
	while (s)
	{
		if (s->t > 0 && s->t < min)
		{
			min = s->t;
			temp = s;
		}
		s = s->next;
	}
	s = temp3;
	temp2 = copy_list(temp);
	free_solution(s);
	return (temp2);
}

t_solution	*get_min_ll_shadow(t_solution *s, t_solution *sol)
{
	t_solution	*temp;
	t_solution	*temp2;
	t_solution	*temp3;
	double		min;

	temp = NULL;
	min = DBL_MAX;
	temp3 = s;
	while (s)
	{
		if ((s->t > 0 && s->t < min)
			&& !(s->type == sol->type && s->id == sol->id))
		{
			min = s->t;
			temp = s;
		}
		s = s->next;
	}
	s = temp3;
	temp2 = copy_list(temp);
	free_solution(s);
	return (temp2);
	return (temp);
}
