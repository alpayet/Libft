/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 04:29:56 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 02:03:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_iter(t_list *lst, void (*f)(void *))
{
	t_lst_node	*node;

	if (lst == NULL || f == NULL)
		return ;
	node = lst->first;
	while (node != NULL)
	{
		f(node->content);
		node = node->next;
	}
}
