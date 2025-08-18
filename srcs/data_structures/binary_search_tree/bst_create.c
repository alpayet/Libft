/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:50:03 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 18:50:11 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bst_node	*bst_node_create(void *key, void *value);

bst	*bst_create(void *key, void *value,
				int (*key_cmp)(void *first_key, void *second_key))
{
	bst	*tree;

	if (key == NULL || key_cmp == NULL)
		return (NULL);
	tree = malloc(sizeof(*tree));
	if (tree == NULL)
		return (NULL);
	tree->root = bst_node_create(key, value);
	if (tree->root == NULL)
	{
		free(tree);
		return (NULL);
	}
	tree->key_cmp = key_cmp;
	return (tree);
}

bst_node	*bst_node_create(void *key, void *value)
{
	bst_node	*node;

	if (key == NULL)
		return (NULL);
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->key = key;
	node->value = value;
	node->right = NULL;
	return (node);
}