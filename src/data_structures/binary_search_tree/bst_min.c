/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:17:58 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:53:54 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	*bst_min_recursive(t_bst_node *root);
void	bst_remove_min(t_bst *tree, void (*del)(void *));
void	bst_delete_node(t_bst_node *node, void (*del)(void *));

void	*bst_min(t_bst *tree)
{
	if (tree == NULL)
		return (NULL);
	return (bst_min_recursive(tree->root));
}

void	*bst_min_recursive(t_bst_node *root)
{
	if (root->left == NULL)
		return (root->key);
	return (bst_min_recursive(root->left));
}
