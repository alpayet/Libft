/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:19:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 03:44:08 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
t_list *hashtbl_bucket(hashtbl *h, char *key);
entry *hashtbl_find_entry(t_list *bucket, char *key);

bool hashtbl_contains(hashtbl *h, char *key)
{
	t_list	*bucket;

	if (h == NULL || key == NULL)
		return (false);
	bucket = hashtbl_bucket(h, key);
	if (bucket == NULL)
		return (false);
	return (hashtbl_find_entry(bucket, key) != NULL);
}

