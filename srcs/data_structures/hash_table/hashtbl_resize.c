/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:01:08 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 17:54:18 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
size_t hash(char *key);
t_hashtbl_status hashtbl_bucket_prepend(vector *vect, t_list **bucket,
	char *key, void *value);
void bucket_clear(void *bucket);

static bool	insert_in_new_vect(vector *new_vector, entry *node_entry)
{
	size_t	new_index;
	t_list	*new_bucket;

	new_index = hash(node_entry->key) % new_vector->capacity;
	new_bucket = vector_get(new_vector, new_index);
	if (hashtbl_bucket_prepend(new_vector, &new_bucket,
		node_entry->key, node_entry->value) == HASHTBL_ERR_ALLOC)
		return (false);
	return (true);
}

static bool	reinsert_hashtbl_elements(vector *old_vector, vector *new_vector)
{
	size_t	i;
	t_list	*old_bucket;
	t_list	*new_bucket;
	entry	*node_entry;
	size_t	new_index;

	i = 0;
	while (i < old_vector->size)
	{
		old_bucket = vector_get(old_vector, i);
		while (old_bucket != NULL)
		{
			node_entry = (entry *)(old_bucket->content);
			if (node_entry != NULL)
			{
				if (insert_in_new_vect(new_vector, node_entry) == false)
					return (false);
			}
			old_bucket = ft_lstnext(old_bucket);
		}
		i++;
	}
	return (true);
}

static size_t get_new_capacity(hashtbl *h)
{
	if (h->vect->capacity == 0)
		return (INITIAL_BUCKET_COUNT);
	else
		return (h->vect->capacity);
}

bool	hashtbl_resize(hashtbl *h)
{
	float	load_factor;
	size_t	new_capacity;
	vector	*old_vector;
	vector	*new_vector;

	if (h == NULL || h->vect == NULL)
		return (true);
	new_capacity = get_new_capacity(h);
	load_factor = (float)h->count / (float)new_capacity;
	if (load_factor > HASHTBL_LOAD_FACTOR_LIMIT)
	{
		new_capacity *= 2;
		old_vector = h->vect;
		new_vector = vector_create(new_capacity, h->vect->element_size);
		if (new_vector == NULL)
			return (false);
		if (reinsert_hashtbl_elements(old_vector, new_vector) == false)
		{
			vector_delete(new_vector, bucket_clear);
			return (false);
		}
		h->vect = new_vector;
		vector_delete(old_vector, bucket_clear);
	}
	return (true);
}
