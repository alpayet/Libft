/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_bucket_prepend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 04:18:37 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 00:17:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
void	hashtbl_change_bucket_head(vector *vect, t_list *new_bucket_head, char *key);

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

t_hashtbl_status hashtbl_bucket_prepend(vector *vect, t_list **bucket, char *key, void *value)
{
	t_list	*new_node;
	entry	*entry;

	if (vect == NULL || key == NULL)
		return (HASHTBL_ERR_INVALID);
	entry = new_entry(key, value);
	if (entry == NULL)
		return (HASHTBL_ERR_ALLOC);
	new_node = lst_new(entry);
	if (new_node == NULL)
	{
		free(entry);
		return (HASHTBL_ERR_ALLOC);
	}
	lst_add_front(bucket, new_node);
	hashtbl_change_bucket_head(vect, bucket, key);
	return (HASHTBL_OK);
}
