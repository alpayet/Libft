/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 04:09:08 by alpayet           #+#    #+#             */
/*   Updated: 2025/08/24 22:34:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list	*hashtbl_bucket(hashtbl *h, void *key);
void	hashtbl_change_bucket(vector *vect, t_list **new_bucket_ptr, void *key);

void	hashtbl_remove(hashtbl *h, void *key)
{
	t_list	*bucket;
	t_lst_node	*prev;
	t_lst_node	*curr;

	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return ;
	prev = NULL;
	curr = bucket->first;
	while (curr != NULL)
	{
		if (curr->content != NULL
			&& h->key_cmp(key, ((entry *)(curr->content))->key) == 0)
		{
			if (prev == NULL)
				lst_remove_first(bucket, free);
			else
				lst_remove_after(bucket, prev, free);
			if (h->count != 0)
				h->count--;
			return ;
		}
		prev = curr;
		curr = lst_node_next(curr);
	}
}
