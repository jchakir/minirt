/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:16:34 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/03 12:18:59 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_sphere	*last(t_sphere *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	add_spheres_back(t_sphere **spheres, t_sphere *new)
{
	t_sphere	*temp;

	if (*spheres == NULL)
	{
		*spheres = new;
		(*spheres)->next = NULL;
		return ;
	}
	temp = last(*spheres);
	temp->next = new;
}
