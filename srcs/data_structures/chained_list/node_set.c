/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:44:00 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 02:38:26 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	node_set(t_node *node, void *content)
{
	if (node == NULL)
		return ;
	node->content = content;
}