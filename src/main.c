/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:01:06 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:25:19 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"

int	check_extension(char *str)
{
	char	*ext;

	if (! ft_strcmp(str, ".rt"))
		return (0);
	ext = ft_strrchr(str, '.');
	if (!ext)
		return (0);
	if (!ft_strcmp(ext, ".rt"))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*buffer;
	int		fd;

	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			ft_error("Not a valid extension file");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[1]);
			exit(1);
		}
		buffer = read_file(fd);
		parse_config(&data, buffer);
		create_frame(data);
	}
}
