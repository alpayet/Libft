/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:38:04 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:57:40 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

bool	stack_is_empty(t_stack *stk)
{
	return (stk == NULL || stk->vect == NULL || stk->vect->size == 0);
}
