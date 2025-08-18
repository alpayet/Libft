/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:44:05 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:38:12 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	*lst_node_get(t_lst_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->content);
}