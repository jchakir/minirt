/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:44:50 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:00 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parse_camera(char **subline, t_data *data)
{
	data->camera = malloc(sizeof(t_camera));
	if (!data->camera)
		return ;
	if (get_tab_size(subline) != 4)
		ft_error("Too many or few arguments");
	get_xyz_points(&data->camera->point, subline[1]);
	get_xyz_vectors(&data->camera->vector, subline[2]);
	if (!(ft_atoi(subline[3]) >= 0 && ft_atoi(subline[3]) < 180))
		ft_error("Horizontal field not valid");
	data->camera->fov = ft_atoi(subline[3]);
}
