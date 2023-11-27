/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:02:58 by hbourkan          #+#    #+#             */
/*   Updated: 2021/11/09 20:25:11 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compteur_nombre(int n)
{
	int		cpt;
	long	n2;

	cpt = 0;
	n2 = n;
	if (n2 < 0)
		n2 = n2 * -1;
	if (n2 == 0)
		return (1);
	while (n2 > 0)
	{
		n2 = n2 / 10;
		cpt++;
	}
	return (cpt);
}

static int	powerof(int nb, int power)
{
	int	i;
	int	nb2;

	i = 0;
	nb2 = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb2 = nb2 * nb;
		power--;
	}
	return (nb2);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;
	long	n3;
	int		cpt;

	n2 = n;
	n3 = 0;
	cpt = compteur_nombre(n);
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = n2 * -1;
	}
	while (cpt > 0)
	{
		n3 = n2 / powerof(10, cpt - 1);
		ft_putchar_fd(n3 % 10 + '0', fd);
		cpt--;
	}
}
