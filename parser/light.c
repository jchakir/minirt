/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:44:58 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:23 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parse_light(char **subline, t_data *data)
{
	data->light = malloc(sizeof(t_light));
	if (!data->light)
		return ;
	if (get_tab_size(subline) != 4)
		ft_error("Too many or few arguments");
	get_xyz_points(&data->light->point, subline[1]);
	if (!(ft_atof(subline[2]) >= 0.0 && ft_atof(subline[2]) <= 1.0))
		ft_error("Light brightness ratio not valid");
	data->light->ratio = ft_atof(subline[2]);
}
