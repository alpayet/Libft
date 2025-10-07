/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_traverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:23:32 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/14 17:32:02 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void	bin_tree_traverse_preorder(bin_tree *tree, void (*f)(void *))
{
	if (tree == NULL)
		return ;
	if (f != NULL)
		f(tree->content);
	bin_tree_traverse_preorder(tree->left, f);
	bin_tree_traverse_preorder(tree->right, f);
}

void	bin_tree_traverse_inorder(bin_tree *tree, void (*f)(void *))
{
	if (tree == NULL)
		return ;
	bin_tree_traverse_inorder(tree->left, f);
	if (f != NULL)
		f(tree->content);
	bin_tree_traverse_inorder(tree->right, f);
}

void	bin_tree_traverse_postorder(bin_tree *tree, void (*f)(void *))
{
	if (tree == NULL)
		return ;
	bin_tree_traverse_postorder(tree->left, f);
	bin_tree_traverse_postorder(tree->right, f);
	if (f != NULL)
		f(tree->content);
}
