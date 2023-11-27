/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:42:50 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:03 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_cylinder	*parse_cylinder(char **subline)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	if (get_tab_size(subline) != 6)
		ft_error("Too many or few arguments");
	get_xyz_points(&cylinder->point, subline[1]);
	get_xyz_vectors(&cylinder->vector, subline[2]);
	cylinder->diameter = ft_atof(subline[3]);
	cylinder->height = ft_atof(subline[4]);
	get_rgb_colors(&cylinder->rgb, subline[5]);
	cylinder->next = NULL;
	return (cylinder);
}
