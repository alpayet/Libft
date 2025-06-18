/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:24:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/18 04:33:43 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	ft_lst_remove_if(t_list **lst, void *data_ref, bool (*cmp)(void*, void*), void (*del)(void*))
{
	t_list	*curr;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || !cmp || !del)
		return ;
	while (*lst != NULL && cmp((*lst)->content, data_ref) == true)
	{
		curr = *lst;
		*lst = (*lst)->next;
		del(curr);
	}
	curr = *lst;
	while (curr)
	{
		if (cmp(curr->content, data_ref) == true)
		{
			prev->next = curr->next;
			del(curr);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

