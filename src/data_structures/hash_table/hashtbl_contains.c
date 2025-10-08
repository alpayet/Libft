/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:19:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:52 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_list	*hashtbl_bucket(t_hashtbl *h, void *key);
t_entry	*hashtbl_find_entry(t_list *bucket, void *key,
			int (*key_cmp)(void *first_key, void *second_key));

bool	hashtbl_contains(t_hashtbl *h, void *key)
{
	t_list	*bucket;

	if (h == NULL || key == NULL)
		return (false);
	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return (false);
	return (hashtbl_find_entry(bucket, key, h->key_cmp) != NULL);
}
