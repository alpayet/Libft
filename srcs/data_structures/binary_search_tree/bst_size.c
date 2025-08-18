/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:59:40 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/16 00:08:19 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static size_t	bst_size_recursive(bst_node *root);

size_t	bst_size(bst *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_size_recursive(tree->root));
}

static size_t	bst_size_recursive(bst_node *root)
{
	if (root == NULL)
		return (0);
	return (bst_size_recursive(root->left) + bst_size_recursive(root->right) + 1);
}