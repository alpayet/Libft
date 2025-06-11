/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:14:26 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/11 13:17:13 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void *stack_pop(stack *stk)
{
	void	*top;

	if (stk->vect->size == 0)
		return (NULL);
	top = vector_get(stk->vect, stk->vect->size - 1);
	stk->vect->size = stk->vect->size - 1;
	return (top);
}