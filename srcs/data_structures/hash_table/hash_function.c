/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:37:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/06/21 17:57:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	hash(char *key)
{
	size_t	result;

	result = 0;
	if (key == NULL)
		return (0);
	while (*key != '\0')
	{
		result = result * 31 + (unsigned char)(*key);
		key++;
	}
	return (result);
}
