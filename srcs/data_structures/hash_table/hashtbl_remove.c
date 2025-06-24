/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 04:09:08 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/24 06:18:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list	*hashtbl_bucket(hashtbl *h, char *key);
void	hashtbl_change_bucket(vector *vect, t_list **new_bucket_ptr, char *key);

void	hashtbl_remove(hashtbl *h, char *key)
{
	t_list	*bucket;
	t_node	*prev;
	t_node	*curr;

	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return ;
	prev = NULL;
	curr = bucket->first;
	while (curr != NULL)
	{
		if (curr->content != NULL
			&& ft_strcmp(key, ((entry *)(curr->content))->key) == 0)
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
		curr = node_next(curr);
	}
}
