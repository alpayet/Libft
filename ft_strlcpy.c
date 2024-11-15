/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:37:35 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/11 17:00:31 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	while ((size != 0) && (i < (size - 1)) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (j);
}

/*#include <string.h>
int	main(void)
{
	char src[] = "Bonjour";
    	char dst[10];

	printf("%zu \n", ft_strlcpy(dst,src, 2));
	printf("%s", dst);
}*/