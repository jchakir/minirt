/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:25:07 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 20:03:27 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

char	*get_next_line_str(char **str)
{
	char	*line;
	char	*temp;
	int		i;

	if (ft_strchr(*str, '\n') != -1)
	{
		i = ft_strchr(*str, '\n');
		line = ft_substr(*str, 0, i);
		temp = *str;
		*str = ft_substr(*str, i + 1, ft_strlen(*str + i));
		free(temp);
	}
	else
	{
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
	return (line);
}
