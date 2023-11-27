/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:01:19 by hbourkan          #+#    #+#             */
/*   Updated: 2022/05/16 18:58:56 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_i(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	return (i);
}

static int	find_j(char const *s1, char const *set)
{
	int	j;
	int	l;

	l = ft_strlen(s1) - 1;
	j = 0;
	while (l > 0)
	{
		if (ft_strchr(set, s1[l]))
		{
			l--;
			j++;
		}
		else
			break ;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = find_i(s1, set);
	j = find_j(s1, set);
	if (s1[i] == '\0')
		s = ft_strdup("");
	else
		s = ft_strndup(s1 + i, ft_strlen(s1 + i) - j);
	return (s);
}
