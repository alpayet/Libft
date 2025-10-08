/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:21:13 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:49 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	hash(void *key);
t_list	*hashtbl_bucket(t_hashtbl *h, void *key);
t_entry	*hashtbl_find_entry(t_list *bucket, void *key,
			int (*key_cmp)(void *first_key, void *second_key));

void	*hashtbl_get(t_hashtbl *h, void *key)
{
	t_list	*bucket;
	t_entry	*node_entry;

	if (h == NULL || key == NULL)
		return (NULL);
	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return (NULL);
	node_entry = hashtbl_find_entry(bucket, key, h->key_cmp);
	if (node_entry == NULL)
		return (NULL);
	return (node_entry->value);
}
