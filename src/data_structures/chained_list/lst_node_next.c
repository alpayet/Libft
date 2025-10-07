/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:43:57 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:38:38 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_lst_node *lst_node_next(t_lst_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->next);
}