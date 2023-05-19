/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:17:16 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/07 12:54:41 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_plane	*last(t_plane *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	add_planes_back(t_plane **planes, t_plane *new)
{
	t_plane	*temp;

	if (*planes == NULL)
	{
		*planes = new;
		(*planes)->next = NULL;
		return ;
	}
	temp = last(*planes);
	temp->next = new;
}
