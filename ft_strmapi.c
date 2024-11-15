/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:39 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/13 00:25:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_f;
	int		i;

	s_f = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s_f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_f[i] = f(i, s[i]);
		i++;
	}
	s_f[i] = '\0';
	return (s_f);
}
/*char	ft_a(unsigned int i, char a)
{
	return('a' + i);
}
int	main(void)
{
	printf("%s", ft_strmapi("abcde", ft_a));
}*/
