/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:52:06 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 02:04:21 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_bin_tree	*bin_tree_create(t_bin_tree *left, void *content, t_bin_tree *right)
{
	t_bin_tree	*tree;

	tree = malloc(sizeof(*tree));
	if (tree == NULL)
		return (NULL);
	tree->left = left;
	tree->content = content;
	tree->right = right;
	return (tree);
}
