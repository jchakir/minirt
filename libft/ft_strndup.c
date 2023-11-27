/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:54:58 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 22:49:19 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
