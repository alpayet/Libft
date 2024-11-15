/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:41:24 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/07 14:04:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[k])
		k++;
	while ((size != 0) && ((i + j) < (size - 1)) && (src[j] != '\0'))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size < i)
		return (k + size);
	return (i + k);
}

/*#include <string.h>
int	main(void)
{
	char dest[20] = "Bonjour, ";
    	char *src = "monde!";
	printf("%d", ft_strlcat(dest, src, 7));
	printf("%s", dest);
}*/