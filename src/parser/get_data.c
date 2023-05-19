/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:28:43 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:14 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	check_normalized_vector(t_vector vec)
{
	if (!(norm(vec) >= 0.99 && norm(vec) <= 1.01))
		return (0);
	return (1);
}

void	get_xyz_points(t_point *xyz, char *subline)
{
	char	**coordinates;

	if (!check_commas(subline))
		ft_error("Too many or few commas");
	coordinates = ft_split(subline, ',');
	if (get_tab_size(coordinates) != 3)
		ft_error("Too many or few coordinates");
	xyz->x = ft_atof(coordinates[0]);
	xyz->y = ft_atof(coordinates[1]);
	xyz->z = ft_atof(coordinates[2]);
	free_tab(coordinates);
}

void	get_xyz_vectors(t_vector *xyz, char *subline)
{
	char	**coordinates;
	int		i;

	i = 0;
	if (!check_commas(subline))
		ft_error("Too many or few commas");
	coordinates = ft_split(subline, ',');
	if (get_tab_size(coordinates) != 3)
		ft_error("Too many or few coordinates");
	while (coordinates[i])
		if (!((ft_atof(coordinates[i]) >= -1.0
					&& ft_atof(coordinates[i++]) <= 1.0)))
			ft_error("Vector not valid");
	xyz->x = ft_atof(coordinates[0]);
	xyz->y = ft_atof(coordinates[1]);
	xyz->z = ft_atof(coordinates[2]);
	if (!check_normalized_vector(*xyz))
		ft_error("Vector not normalized");
	free_tab(coordinates);
}

void	get_rgb_colors(t_rgb *rgb, char *subline)
{
	char	**colors;
	int		i;

	i = 0;
	if (!check_commas(subline))
		ft_error("Too many or few commas");
	colors = ft_split(subline, ',');
	if (get_tab_size(colors) != 3)
		ft_error("Too many or few colors");
	while (colors[i])
		if (!((ft_atoi(colors[i]) >= 0 && ft_atoi(colors[i++]) <= 255)))
			ft_error("Color not valid");
	rgb->red = ft_atof(colors[0]);
	rgb->green = ft_atof(colors[1]);
	rgb->blue = ft_atof(colors[2]);
	free_tab(colors);
}
