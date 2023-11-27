/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:30:03 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 22:49:38 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
