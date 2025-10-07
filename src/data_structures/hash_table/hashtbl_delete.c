/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtbl_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:29:02 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 05:12:11 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
void bucket_clear(void *bucket);

void hashtbl_delete(hashtbl *h)
{
	if (h == NULL)
		return ;
	vector_delete(h->vect, bucket_clear);
	free(h);
}
