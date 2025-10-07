/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:26:14 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/16 00:26:30 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void *stack_top(stack *stk)
{
	if (stk == NULL || stk->vect == NULL || stk->vect->size == 0)
		return (NULL);
	return (vector_get(stk->vect, stk->vect->size - 1));
}