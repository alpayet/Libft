/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:29:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 06:02:08 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

static void bucket_clear(void *bucket)
{
	t_list *lst;

	lst = (t_list *)bucket;
	ft_lstclear(&lst, free);
}

void hashtbl_delete(hashtbl *h)
{
	if (h == NULL)
		return ;
	vector_delete(h->vect, bucket_clear);
	free(h);
}
