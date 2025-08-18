/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:26:36 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/14 16:42:58 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	bin_tree_delete(bin_tree *tree, void (*del)(void *))
{
	if (tree == NULL)
		return ;
	bin_tree_delete(tree->left, del);
	bin_tree_delete(tree->right, del);
	if (del != NULL)
		del(tree->content);
	free(tree);
}