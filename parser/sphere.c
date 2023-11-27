/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:43:15 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:31 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_sphere	*parse_sphere(char **subline)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	if (get_tab_size(subline) != 4)
		ft_error("Too many or few arguments");
	get_xyz_points(&sphere->point, subline[1]);
	sphere->diameter = ft_atof(subline[2]);
	get_rgb_colors(&sphere->rgb, subline[3]);
	sphere->next = NULL;
	return (sphere);
}
