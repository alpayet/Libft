/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:33:24 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/10 13:50:30 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_alt;

	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next_alt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_alt;
	}
}