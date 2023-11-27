/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:07:38 by hbourkan          #+#    #+#             */
/*   Updated: 2021/11/13 18:50:47 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
