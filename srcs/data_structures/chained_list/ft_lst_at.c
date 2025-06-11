/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:43:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/11 13:02:31 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list *ft_lst_at(t_list *lst, size_t index)
{
	while (index != 0 && lst != NULL)
	{
		index--;
		lst = lst->next;
	}
	return (lst);
}
