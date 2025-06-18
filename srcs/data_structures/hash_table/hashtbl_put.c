/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:30:49 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/18 04:00:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
entry *hashtbl_find_entry(t_list *bucket, char *key);

static entry *new_entry(char *key, void *value)
{
	entry	*new_entry;

	new_entry = malloc(sizeof(entry));
	if (new_entry == NULL)
		return (NULL);
	new_entry->key = key;
	new_entry->value = value;
	return(new_entry);
}

static bool hashtbl_bucket_prepend(t_list **bucket, char *key, void *value)
{
	t_list	*new_node;
	entry	*entry;
	size_t	index_in_table;

	entry = new_entry(key, value);
	if (entry == NULL)
		return (false);
	new_node = ft_lstnew(entry);
	if (new_node == NULL)
		return (false);
	ft_lstadd_front(bucket, new_node);
	return (true);
}

bool hashtbl_put(hashtbl *h, char *key, void *value)
{
	t_list	*bucket;
	entry	*entry;
	size_t	index_in_table;

	if (h == NULL || h->vect == NULL || h->vect->size == 0)
		return (false);
	index_in_table = hash(key) % h->vect->size;
	bucket = vector_get(h->vect, index_in_table);
	if (bucket == NULL)
	{
		if (hashtbl_bucket_prepend(&bucket, key, value) == false)
			return (false);
		vector_set(h->vect, index_in_table, bucket);
		return (true);
	}
	entry = hashtbl_find_entry(bucket, key);
	if (entry == NULL)
	{
		if (hashtbl_bucket_prepend(&bucket, key, value) == false)
			return (false);
		vector_set(h->vect, index_in_table, bucket);
	}
	else
		entry->value = value;
}
