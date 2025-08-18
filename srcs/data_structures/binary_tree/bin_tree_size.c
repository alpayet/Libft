/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_tree_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:57:24 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/14 16:09:40 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	bin_tree_size(bin_tree *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + bin_tree_size(tree->left) + bin_tree_size(tree->right));
}