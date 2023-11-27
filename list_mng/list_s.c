/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:54:35 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:52:21 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_solution	*last(t_solution *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	add_s_back(t_solution **s, t_solution *new)
{
	t_solution	*temp;

	if (*s == NULL)
	{
		*s = new;
		(*s)->next = NULL;
		return ;
	}
	temp = last(*s);
	temp->next = new;
}

t_solution	*copy_list(t_solution *temp)
{
	t_solution	*temp2;

	if (!temp)
		return (NULL);
	temp2 = malloc(sizeof(t_solution));
	temp2->solution = temp->solution;
	temp2->t = temp->t;
	temp2->color = temp->color;
	temp2->type = temp->type;
	temp2->id = temp->id;
	temp2->rgb = temp->rgb;
	return (temp2);
}
