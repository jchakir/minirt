/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:53:53 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 22:01:52 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	get_tab_size(char **sublines)
{
	int	c;

	c = 0;
	while (sublines[c])
		c++;
	return (c);
}

void	ft_error(char *error_msg)
{
	printf("Error\n%s...\n", error_msg);
	exit(1);
}

int	is_int(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_commas(char *subline)
{
	int	counter;

	counter = 0;
	while (*subline)
	{
		if (*subline == ',')
			counter++;
		subline++;
	}
	if (counter > 2)
		return (0);
	return (1);
}
