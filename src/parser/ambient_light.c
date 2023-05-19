/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:44:44 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:03:51 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	parse_ab_light(char **subline, t_data *data)
{
	data->amb_light = malloc(sizeof(t_ambient_light));
	if (!data->amb_light)
		return ;
	if (get_tab_size(subline) != 3)
		ft_error("Too many or few arguments");
	if ((!is_int(subline[1]) && !ft_isfloat(subline[1])))
		ft_error("Not a valid data type");
	if (!(ft_atof(subline[1]) >= 0.0f && ft_atof(subline[1]) <= 1.0f))
		ft_error("Invalid ambient lightning ratio");
	data->amb_light->ratio = ft_atof(subline[1]);
	get_rgb_colors(&data->amb_light->rgb, subline[2]);
}
