/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:02:45 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 00:18:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	lst_delone(t_node *node, void (*del)(void*))
{
	if (node == NULL)
		return ;
	if (del != NULL)
		del(node->content);
	free(node);
}