/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:23:59 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/11 16:37:51 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (little[j])
			{
				if (big[i + j] != little[j] || (i + j) >= len)
					break ;
				j++;
			}
		}
		if (j == ft_strlen(little))
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

/*#include <string.h>
int	main(void)
{
	printf("%s", ft_strnstr("abccc", "abcc", 4));
}*/