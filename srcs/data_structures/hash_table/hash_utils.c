/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:31:29 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/15 16:38:38 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	hash(char *key);

size_t	index_in_hashtbl(vector *vect, char *key)
{
	if (vect->capacity == 0)
		return (SIZE_MAX);
	return (hash(key) % vect->capacity);
}

t_list	*hashtbl_bucket(hashtbl *h, char *key)
{
	size_t	index_in_table;
	t_list	**bucket_ptr;

	if (h == NULL || key == NULL || h->vect == NULL)
		return (NULL);
	index_in_table = index_in_hashtbl(h->vect, key);
	if (index_in_table == SIZE_MAX)
		return (NULL);
	bucket_ptr = (t_list **)vector_get(h->vect, index_in_table);
	if (bucket_ptr == NULL)
		return (NULL);
	return (*bucket_ptr);
}

entry	*hashtbl_find_entry(t_list *bucket, char *key)
{
	t_lst_node	*node;
	entry	*node_entry;

	if (bucket == NULL || key == NULL)
		return (NULL);
	node = bucket->first;
	while (node != NULL)
	{
		node_entry = (entry *)(node->content);
		if (node_entry != NULL)
		{
			if (ft_strcmp(key, node_entry->key) == 0)
				return (node_entry);
		}
		node = lst_node_next(node);
	}
	return (NULL);
}

void	hashtbl_change_bucket(vector *vect,
	t_list **new_bucket_ptr, char *key)
{
	size_t	index_in_table;

	if (key == NULL || vect == NULL || new_bucket_ptr == NULL)
		return ;
	index_in_table = index_in_hashtbl(vect, key);
	if (index_in_table == SIZE_MAX)
		return ;
	vector_set(vect, index_in_table, new_bucket_ptr);
}

void	bucket_clear(void *bucket_ptr)
{
	t_list	**lst;

	lst = (t_list **)bucket_ptr;
	lst_clear(*lst, free);
}
