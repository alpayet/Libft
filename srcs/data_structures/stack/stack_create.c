/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:17:54 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/11 21:48:53 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

stack *stack_create(size_t capacity, size_t element_size)
{
	stack	*stk;

	stk = malloc(sizeof(stack));
	if (stk == NULL)
		return (NULL);
	stk->vect = vector_create(capacity, element_size);
	if (stk->vect == NULL)
	{
		free(stk);
		return (NULL);
	}
	return (stk);
}