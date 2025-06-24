/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:33:24 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 00:18:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_clear(t_list *lst, void (*del)(void*))
{
	t_node	*new_first;

	if (lst == NULL)
		return ;
	while (lst->first != NULL)
	{
		new_first = lst->first->next;
		lst_delone(lst->first, del);
		lst->first = new_first;
	}
	free(lst);
}