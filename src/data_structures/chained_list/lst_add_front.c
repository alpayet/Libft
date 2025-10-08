/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:28:01 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:53:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_add_front(t_list *lst, t_lst_node *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = lst->first;
	lst->first = new;
	if (lst->last == NULL)
		lst->last = new;
	lst->size++;
}
