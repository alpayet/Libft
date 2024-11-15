/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:43 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/09 16:33:18 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s1_s2_conc;
	unsigned long	i;
	unsigned long	j;

	s1_s2_conc = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s1_s2_conc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s1_s2_conc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s1_s2_conc[i + j] = s2[j];
		j++;
	}
	s1_s2_conc[i + j] = '\0';
	return (s1_s2_conc);
}

/*int	main(void)
{
	printf("%s\n", ft_strjoin("abcd", "efgh"));
	printf("%s", ft_strjoin("abcd", ""));
}*/
