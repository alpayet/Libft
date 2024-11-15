/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:16:41 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/14 03:51:48 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numof_set_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (count);
}

static int	ft_numof_set_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[ft_strlen(s1) - 1 - i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			index;
	size_t		size_s1_trim;

	if ((size_t)ft_numof_set_start(s1, set) == ft_strlen(s1))
		size_s1_trim = 0;
	else
	{
		size_s1_trim = ft_strlen(s1) - (ft_numof_set_start(s1, set)
				+ ft_numof_set_end(s1, set));
	}
	index = ft_numof_set_start(s1, set);
	return (ft_substr(s1, index, size_s1_trim));
}

/*int	main(void)
{
	printf("%d", ft_numof_set_end("avbaa", "av"));
}*/
