/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:07:23 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void vector_delete(vector *vect)
{
	if (vect == NULL)
		return ;
	free(vect->data);
	free(vect);
}
