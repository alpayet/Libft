/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 04:09:08 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 05:40:26 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list	*hashtbl_bucket(hashtbl *h, char *key);
void	hashtbl_change_bucket_head(vector *vect, t_list *new_bucket_head, char *key);

void	hashtbl_remove(hashtbl *h, char *key)
{
	t_list	*bucket;
	t_list	*prev;
	t_list	*curr;
	entry	*node_entry;

	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return ;
	prev = NULL;
	curr = bucket;
	while (curr != NULL)
	{
		node_entry = (entry *)(curr->content);
		if (node_entry != NULL && ft_strcmp(key, node_entry->key) == 0)
		{
			ft_lstremove_next(&bucket, prev, free);
			if (prev == NULL)
				hashtbl_change_bucket_head(h->vect, bucket, key);
			if (h->count != 0)
				h->count--;
			return ;
		}
		prev = curr;
		curr = ft_lstnext(curr);
	}
}
