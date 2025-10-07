/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:29:00 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/19 02:21:19 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

void stack_delete(stack *stk, void (*del)(void *))
{
	if (stk == NULL)
		return ;
	vector_delete(stk->vect, del);
	free(stk);
}