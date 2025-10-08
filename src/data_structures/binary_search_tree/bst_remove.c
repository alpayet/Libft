/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:29:19 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:49:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_bst_node	*bst_get_node(t_bst *tree, void *key);
static void	bst_remove_min(t_bst *tree, void (*del)(void *));
void		bst_delete_node(t_bst_node *node, void (*del)(void *));

void	bst_remove(t_bst *tree, void *key, void (*del)(void *))
{
	t_bst_node	*target;
	t_bst		*target_right_tree;
	void		*successor_target_key;

	if (tree == NULL || key == NULL)
		return ;
	target = bst_get_node(tree, key);
	target_right_tree = &(t_bst){target->right, tree->key_cmp};
	successor_target_key = bst_min(target_right_tree);
	target->key = successor_target_key;
	target->value = bst_search(target_right_tree, successor_target_key);
	bst_remove_min(target_right_tree, del);
	target->right = target_right_tree->root;
}

static void	bst_remove_min(t_bst *tree, void (*del)(void *))
{
	t_bst_node	*parent;
	t_bst_node	*min;

	if (tree == NULL || tree->root == NULL)
		return ;
	parent = NULL;
	min = tree->root;
	while (min->left != NULL)
	{
		parent = min;
		min = min->left;
	}
	if (parent == NULL)
		tree->root = min->right;
	else
		parent->left = min->right;
	bst_delete_node(min, del);
}
