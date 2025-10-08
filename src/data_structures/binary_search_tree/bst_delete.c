/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:59:01 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:51:10 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void	bst_delete_recursive(t_bst_node *root, void (*del)(void *));
void		bst_delete_node(t_bst_node *node, void (*del)(void *));

void	bst_delete(t_bst *tree, void (*del)(void *))
{
	if (tree == NULL)
		return ;
	bst_delete_recursive(tree->root, del);
	free(tree);
}

static void	bst_delete_recursive(t_bst_node *root, void (*del)(void *))
{
	if (root == NULL)
		return ;
	bst_delete_recursive(root->left, del);
	bst_delete_recursive(root->right, del);
	bst_delete_node(root, del);
}

void	bst_delete_node(t_bst_node *node, void (*del)(void *))
{
	if (node == NULL)
		return ;
	if (del != NULL)
		del(node->value);
	free(node);
}
