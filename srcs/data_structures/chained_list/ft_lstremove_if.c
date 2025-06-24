/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:24:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/22 20:25:09 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void	ft_lst_remove_if_in_head(t_list **lst, void *data_ref,
	bool (*cmp)(void*, void*), void (*del)(void*))
{
	t_list	*curr;

	while (*lst != NULL && cmp((*lst)->content, data_ref) == true)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(curr, del);
	}
}

static void	ft_lst_remove_if_after(t_list *prev, void *data_ref,
	bool (*cmp)(void*, void*), void (*del)(void*))
{
	t_list	*curr;

	if (prev == NULL)
		return ;
	curr = prev->next;
	while (curr)
	{
		if (cmp(curr->content, data_ref) == true)
		{
			prev->next = curr->next;
			ft_lstdelone(curr, del);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

void	ft_lstremove_if(t_list **lst, void *data_ref,
	bool (*cmp)(void*, void*), void (*del)(void*))
{
	if (lst == NULL || *lst == NULL || !cmp)
		return ;
	ft_lst_remove_if_in_head(lst, data_ref, cmp, del);
	ft_lst_remove_if_after(*lst, data_ref, cmp, del);
}
