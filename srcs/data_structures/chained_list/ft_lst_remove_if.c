/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:24:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/11 12:26:58 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	ft_lst_remove_if(t_list **lst, void *data_ref, bool (*cmp)(void*, void*), void (*del)(void*))
{
	t_list	*temp;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || !cmp || !del)
		return ;
	while (*lst != NULL && cmp((*lst)->content, data_ref) == true)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp);
	}
	temp = *lst;
	while (temp)
	{
		if (cmp(temp->content, data_ref) == true)
		{
			prev->next = temp->next;
			del(temp);
			temp = prev->next;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}