/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:31:29 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 00:39:09 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	index_in_hashtbl(vector *vect, char *key)
{
	return (hash(key) % vect->size);
}

t_list	*hashtbl_bucket(hashtbl *h, char *key)
{
	t_list	*bucket;
	size_t	index_in_table;

	if (h == NULL || key == NULL || h->vect == NULL || h->vect->size == 0)
		return (NULL);
	index_in_table = index_in_hashtbl(h->vect, key);
	bucket = vector_get(h->vect, index_in_table);
	return (bucket);
}

entry	*hashtbl_find_entry(t_list *bucket, char *key)
{
	entry	*node_entry;

	if (key == NULL)
		return (NULL);
	while (bucket != NULL)
	{
		node_entry = (entry *)(bucket->content);
		if (node_entry == NULL)
		{
			bucket = node_next(bucket);
			continue ;
		}
		if (ft_strcmp(key, node_entry->key) == 0)
			return (node_entry);
		bucket = node_next(bucket);
	}
	return (NULL);
}

void	hashtbl_change_bucket_head(vector *vect,
	t_list *new_bucket_head, char *key)
{
	size_t	index_in_table;

	if (key == NULL || vect == NULL || vect->size == 0)
		return ;
	index_in_table = index_in_hashtbl(vect, key);
	vector_set(vect, index_in_table, new_bucket_head);
}

void	bucket_clear(void *bucket)
{
	t_list	*lst;

	lst = (t_list *)bucket;
	lst_clear(&lst, free);
}
