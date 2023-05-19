/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:27:04 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/08 23:53:09 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	free_solution(t_solution *s)
{
	t_solution	*temp;

	while (s)
	{
		temp = s->next;
		free(s);
		s = temp;
	}
}
