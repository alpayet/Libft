/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:24:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:57 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_remove_if(t_list *lst, void *data_ref, bool (*cmp)(void *, void *),
		void (*del)(void *))
{
	t_lst_node	*prev;
	t_lst_node	*curr;

	if (lst == NULL || cmp == NULL)
		return ;
	while (lst->first != NULL && cmp(lst->first->content, data_ref) == true)
		lst_remove_first(lst, del);
	prev = lst->first;
	if (prev == NULL)
		return ;
	curr = prev->next;
	while (curr)
	{
		if (cmp(curr->content, data_ref) == true)
		{
			lst_remove_after(lst, prev, del);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
