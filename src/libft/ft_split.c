/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:29:58 by hbourkan          #+#    #+#             */
/*   Updated: 2022/05/16 18:58:21 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_chaine(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			cpt++;
		i++;
	}
	if (s[i - 1] == c)
		cpt--;
	return (cpt + 1);
}

static int	compteur_carac(char const *s, char c, int i)
{	
	int	cpt;

	cpt = 0;
	while (s[i] != c && s[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**s_array;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	s_array = malloc(sizeof(char *) * (nb_chaine(s, c) + 1));
	if (s_array == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			s_array[j++] = ft_strndup(s + i, compteur_carac(s, c, i));
			i += compteur_carac(s, c, i);
		}
		else
			i++;
	}
	s_array[j] = NULL;
	return (s_array);
}
