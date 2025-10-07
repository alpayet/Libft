/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:12:50 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:37:35 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_add_back(t_list *lst, t_lst_node *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = NULL;
	if (lst->first == NULL)
	{
		lst->first = new;
		lst->last = new;
		return ;
	}
	lst->last->next = new;
	lst->last = new;
	lst->size++;
}
