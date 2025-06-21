/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:21:13 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 03:44:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
size_t hash(char *key);
t_list *hashtbl_bucket(hashtbl *h, char *key);
entry *hashtbl_find_entry(t_list *bucket, char *key);

void *hashtbl_get(hashtbl *h, char *key)
{
	t_list	*bucket;
	entry	*node_entry;

	if (h == NULL || key == NULL)
		return (NULL);
	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return (NULL);
	node_entry = hashtbl_find_entry(bucket, key);
	if (node_entry == NULL)
		return (NULL);
	return (node_entry->value);
}
