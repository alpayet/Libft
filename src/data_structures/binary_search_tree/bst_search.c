/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:54:35 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:54:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	*bst_search(t_bst *tree, void *key)
{
	t_bst_node	*temp;

	if (tree == NULL || key == NULL)
		return (NULL);
	temp = tree->root;
	while (temp != NULL)
	{
		if (tree->key_cmp(key, temp->key) < 0)
			temp = temp->left;
		else if (tree->key_cmp(key, temp->key) > 0)
			temp = temp->right;
		else
			return (temp->value);
	}
	return (NULL);
}

t_bst_node	*bst_get_node(t_bst *tree, void *key)
{
	t_bst_node	*temp;

	if (tree == NULL || key == NULL)
		return (NULL);
	temp = tree->root;
	while (temp != NULL)
	{
		if (tree->key_cmp(key, temp->key) < 0)
			temp = temp->left;
		else if (tree->key_cmp(key, temp->key) > 0)
			temp = temp->right;
		else
			return (temp);
	}
	return (NULL);
}
