/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:33:24 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/14 04:25:28 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_alt;

	if (*lst == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		next_alt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_alt;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}