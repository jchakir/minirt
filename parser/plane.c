/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:43:22 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:29 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_plane	*parse_plane(char **subline)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	if (get_tab_size(subline) != 4)
		ft_error("Too many or few arguments");
	get_xyz_points(&plane->point, subline[1]);
	get_xyz_vectors(&plane->vector, subline[2]);
	get_rgb_colors(&plane->rgb, subline[3]);
	plane->next = NULL;
	return (plane);
}
