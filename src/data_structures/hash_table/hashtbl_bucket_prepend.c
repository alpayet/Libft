/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_bucket_prepend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 04:18:37 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/24 22:36:06 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list	*hashtbl_bucket(hashtbl *h, void *key);
void	hashtbl_change_bucket(vector *vect, t_list **new_bucket_ptr, void *key);

static entry *new_entry(void *key, void *value)
{
	entry	*new_entry;

	new_entry = malloc(sizeof(entry));
	if (new_entry == NULL)
		return (NULL);
	new_entry->key = key;
	new_entry->value = value;
	return(new_entry);
}

t_hashtbl_status hashtbl_bucket_prepend(vector *vect, t_list *bucket, void *key, void *value)
{
	entry	*entry;
	t_lst_node	*new_node;

	if (vect == NULL || key == NULL)
		return (HASHTBL_ERR_INVALID);
	entry = new_entry(key, value);
	if (entry == NULL)
		return (HASHTBL_ERR_ALLOC);
	if (bucket == NULL)
	{
		bucket = lst_new(entry);
		if (bucket == NULL)
		{
			free(entry);
			return (HASHTBL_ERR_ALLOC);
		}
		hashtbl_change_bucket(vect, &bucket, key);
	}
	else
	{
		new_node = lst_node_new(entry);
		if (new_node == NULL)
		{
			free(entry);
			return (HASHTBL_ERR_ALLOC);
		}
		lst_add_front(bucket, new_node);
	}
	return (HASHTBL_OK);
}
