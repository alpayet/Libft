/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:59:32 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:55:09 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	size_t	i;

	i = 0;
	if (len == 0 || s == NULL || start >= ft_strlen(s))
	{
		s_copy = malloc(1);
		if (s_copy == NULL)
			return (NULL);
		s_copy[0] = '\0';
		return (s_copy);
	}
	while ((s + start)[i] != '\0' && i < len)
		i++;
	s_copy = malloc((i + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	ft_strlcpy(s_copy, s + start, i + 1);
	return (s_copy);
}

/*int	main(void)
{
	char str[]= "Hola";
	printf("%s\n", ft_substr(str, 0, 3));

	printf("%s\n", str);
}*/