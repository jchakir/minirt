/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:09:04 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:24:44 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	set_aspect_ratio(t_data *data)
{
	data->aspect_ratio = IMAGE_WIDTH / IMAGE_HEIGHT;
}

static void	set_tan_fov(t_data *data)
{
	data->tanfov = tan((data->camera->fov / 2) * M_PI / 180);
}

static void	check_object_type(char *line, t_data *data)
{
	char	**subline;

	subline = ft_split(line, ' ');
	if (!ft_strcmp(subline[0], "A"))
		parse_ab_light(subline, data);
	else if (!ft_strcmp(subline[0], "C"))
		parse_camera(subline, data);
	else if (!ft_strcmp(subline[0], "L"))
		parse_light(subline, data);
	else if (!ft_strcmp(subline[0], "sp"))
		add_spheres_back(&data->sphere, parse_sphere(subline));
	else if (!ft_strcmp(subline[0], "pl"))
		add_planes_back(&data->plane, parse_plane(subline));
	else if (!ft_strcmp(subline[0], "cy"))
		add_cylinders_back(&data->cylinder, parse_cylinder(subline));
	else
		ft_error("Invalid identifier");
	free_tab(subline);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	*line;

	buffer = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		buffer = ft_strjoin_gnl(buffer, line);
		free(line);
	}
	return (buffer);
}

void	parse_config(t_data *data, char *buffer)
{
	char	*line;

	check_buffer(buffer);
	data->sphere = NULL;
	data->plane = NULL;
	data->cylinder = NULL;
	while (1)
	{
		line = get_next_line_str(&buffer);
		if (line[0] == '\0')
		{
			if (!buffer)
				break ;
			continue ;
		}
		check_object_type(line, data);
		free(line);
		if (!buffer)
			break ;
	}
	set_aspect_ratio(data);
	set_tan_fov(data);
}
