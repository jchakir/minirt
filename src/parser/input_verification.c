/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:42:00 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 18:04:20 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_buffer(char *buffer)
{
	int	counter_amb_lights;
	int	counter_cameras;
	int	counter_lights;
	int	i;

	counter_amb_lights = 0;
	counter_cameras = 0;
	counter_lights = 0;
	i = 0;
	if (*buffer == '\0')
		ft_error("Empty config file");
	while (buffer[i])
	{
		if (buffer[i] == 'A' && buffer[i + 1] == ' ')
			counter_amb_lights++;
		else if (buffer[i] == 'C' && buffer[i + 1] == ' ')
			counter_cameras++;
		else if (buffer[i] == 'L' && buffer[i + 1] == ' ')
			counter_lights++;
		i++;
	}
	if (counter_amb_lights != 1 || counter_cameras != 1 || counter_lights != 1)
		ft_error("Too many or few cameras/ambient lights/lights");
}
