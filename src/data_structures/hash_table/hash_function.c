/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:37:51 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:52:54 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

size_t	hash(void *key)
{
	char	*key_str;
	size_t	result;

	result = 0;
	if (key == NULL)
		return (0);
	key_str = (char *)key;
	while (*key_str != '\0')
	{
		result = result * 31 + (unsigned char)(*key_str);
		key_str++;
	}
	return (result);
}
