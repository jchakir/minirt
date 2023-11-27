/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:38:58 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 20:22:09 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_isfloat(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '.')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != 'e'
			&& str[i] != 'E' && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

static int	ft_atof_helper(char *s, int *i, double *a, int *e)
{
	int	sign;

	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (s[*i] && ft_isdigit(s[*i]))
		*a = *a * 10.0 + (s[(*i)++] - '0');
	if (s[*i] == '.')
	{
		(*i)++;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			*a = *a * 10.0 + (s[(*i)++] - '0');
			(*e)--;
		}
	}
	return (sign);
}

static void	ft_atof_helper2(char *s, int *i, int *sign, int *e)
{
	int	j;

	j = 0;
	if (s[*i] == 'e' || s[*i] == 'E')
	{
		(*i)++;
		if (s[*i] == '+')
			(*i)++;
		else if (s[*i] == '-')
		{
			(*i)++;
			*sign = -1;
		}
		while (ft_isdigit(s[*i]))
			j = j * 10 + (s[(*i)++] - '0');
		*e += j * *sign;
	}
}

double	ft_atof(char *s)
{
	double	a;
	int		e;
	int		i;
	int		sign;

	a = 0.0;
	e = 0;
	i = 0;
	if (!ft_isfloat(s))
		ft_error("Not a valid number");
	sign = ft_atof_helper(s, &i, &a, &e);
	ft_atof_helper2(s, &i, &sign, &e);
	while (e > 0)
	{
		a *= 10.0;
		e--;
	}
	while (e < 0)
	{
		a *= 0.1;
		e++;
	}
	return (a * sign);
}
