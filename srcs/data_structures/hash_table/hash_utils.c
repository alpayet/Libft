/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:31:29 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 05:53:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list *hashtbl_bucket(hashtbl *h, char *key)
{
	t_list	*bucket;
	size_t	index_in_table;

	if (h == NULL || key == NULL || h->vect == NULL || h->vect->size == 0)
		return (NULL);
	index_in_table = hash(key) % h->vect->size;
	bucket = vector_get(h->vect, index_in_table);
	return (bucket);
}

entry *hashtbl_find_entry(t_list *bucket, char *key)
{
	entry	*node_entry;

	if (key == NULL)
		return (NULL);
	while (bucket != NULL)
	{
		node_entry = (entry *)(bucket->content);
		if (node_entry == NULL)
		{
			bucket = ft_lstnext(bucket);
			continue ;
		}
		if (ft_strcmp(key, node_entry->key) == 0)
			return (node_entry);
		bucket = ft_lstnext(bucket);
	}
	return (NULL);
}

void	hashtbl_change_bucket_head(hashtbl *h, t_list *new_bucket_head, char *key)
{
	size_t	index_in_table;

	if (h == NULL || key == NULL || h->vect == NULL || h->vect->size == 0)
		return ;
	index_in_table = hash(key) % h->vect->size;
	vector_set(h->vect, index_in_table, new_bucket_head);
}

bool	hashtbl_resize(hashtbl *h)
{
	float	load_factor;
	size_t	new_capacity;

	if (h == NULL || h->vect == NULL)
		return (true);
	if (h->vect->capacity == 0)
		new_capacity = INITIAL_BUCKET_COUNT;
	else
		new_capacity = h->vect->capacity;
	load_factor = (float)h->count / (float)new_capacity;
	if (load_factor > HASHTBL_LOAD_FACTOR_LIMIT)
	{
		new_capacity *= 2;
		if (vector_resize(h->vect, new_capacity) == false)
			return (false);
	}
	return (true);
}


