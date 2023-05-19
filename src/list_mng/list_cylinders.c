/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:17:20 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/06 19:36:27 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_cylinder	*last(t_cylinder *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	add_cylinders_back(t_cylinder **cylinders, t_cylinder *new)
{
	t_cylinder	*temp;

	if (*cylinders == NULL)
	{
		*cylinders = new;
		(*cylinders)->next = NULL;
		return ;
	}
	temp = last(*cylinders);
	temp->next = new;
}
