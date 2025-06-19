/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:53:41 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 04:53:50 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void ft_lstremove_next(t_list **lst, t_list *prev, void (*del)(void*))
{
	t_list *curr;

	if (lst == NULL || *lst == NULL || !del)
		return ;
	if (prev == NULL)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(curr, del);
		return ;
	}
	curr = prev->next;
	if (curr != NULL)
	{
		prev->next = curr->next;
		ft_lstdelone(curr, del);
	}
}