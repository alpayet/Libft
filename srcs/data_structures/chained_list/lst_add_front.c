/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:28:01 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 01:26:50 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_add_front(t_list *lst, t_node *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = lst->first;
	lst->first = new;
	if (lst->last == NULL)
		lst->last = new;
	lst->size++;
}

