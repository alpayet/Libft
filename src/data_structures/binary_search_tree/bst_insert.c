/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:57:44 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:49:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static bool	bst_insert_child(t_bst_node **node, void *key, void *value);
t_bst_node	*bst_node_create(void *key, void *value);
static bool	change_node_value(t_bst_node *node, void *value);

bool	bst_insert(t_bst *tree, void *key, void *value)
{
	t_bst_node	*temp;

	if (tree == NULL || key == NULL)
		return (false);
	temp = tree->root;
	while (temp != NULL)
	{
		if (tree->key_cmp(key, temp->key) < 0)
		{
			if (temp->left == NULL)
				return (bst_insert_child(&(temp->left), key, value));
			temp = temp->left;
		}
		else if (tree->key_cmp(key, temp->key) > 0)
		{
			if (temp->right == NULL)
				return (bst_insert_child(&(temp->right), key, value));
			temp = temp->right;
		}
		else
			return (change_node_value(temp, value));
	}
	return (false);
}

static bool	bst_insert_child(t_bst_node **node, void *key, void *value)
{
	*node = bst_node_create(key, value);
	return (*node != NULL);
}

static bool	change_node_value(t_bst_node *node, void *value)
{
	node->value = value;
	return (true);
}
