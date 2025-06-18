/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:31:29 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/18 04:24:34 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list *hashtbl_bucket(hashtbl *h, char *key)
{
	t_list	*bucket;
	size_t	index_in_table;

	if (h == NULL || h->vect == NULL || h->vect->size == 0)
		return (NULL);
	index_in_table = hash(key) % h->vect->size;
	bucket = vector_get(h->vect, index_in_table);
	return (bucket);
}

entry *hashtbl_find_entry(t_list *bucket, char *key)
{
	entry	*node_entry;

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


