/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:30:49 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 06:09:03 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list *hashtbl_bucket(hashtbl *h, char *key);
void	hashtbl_change_bucket_head(hashtbl *h, t_list *new_bucket_head, char *key);
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

	if (h == NULL || key == NULL || h->vect == NULL)
		return (false);
	hashtbl_resize(h);
	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
	{
		if (hashtbl_bucket_prepend(&bucket, key, value) == false)
			return (false);
		hashtbl_change_bucket_head(h, bucket, key);
		h->count++;
		return (true);
	}
	entry = hashtbl_find_entry(bucket, key);
	if (entry == NULL)
	{
		if (hashtbl_bucket_prepend(&bucket, key, value) == false)
			return (false);
		hashtbl_change_bucket_head(h, bucket, key);
		h->count++;
	}
	else
		entry->value = value;
	return (true);
}
