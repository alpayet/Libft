/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_perfect_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:15:25 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/14 17:01:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bin_tree	*bin_tree_perfect_create(size_t height, void (*del)(void *))
{
	bin_tree	*tree_perfect;

	tree_perfect = malloc(sizeof(*tree_perfect));
	if (tree_perfect == NULL)
		return (NULL);
	if (height == 0)
	{
		tree_perfect->left = NULL;
		tree_perfect->right = NULL;
		return (tree_perfect);
	}
	tree_perfect->left = bin_tree_perfect_create(height - 1, del);
	if (tree_perfect->left == NULL)
	{
		free(tree_perfect);
		return (NULL);
	}
	tree_perfect->right = bin_tree_perfect_create(height - 1, del);
	if (tree_perfect->right == NULL)
	{
		bin_tree_delete(tree_perfect->left, del);
		free(tree_perfect);
		return (NULL);
	}
	return (tree_perfect);
}
