/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:27 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/14 05:14:37 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				j++;
			}
			i = i + j - 1;
		}
		i++;
	}
	return (count);
}

static void	ft_word_size(char const *s, char **s_split, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				j++;
			}
			s_split[index] = ft_calloc(1, j + 1);
			index++;
			i = i + j - 1;
		}
		i++;
	}
}

static void	ft_filling(char const *s, char **s_split, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while ((s + i)[j])
			{
				if ((s + i)[j] == c)
					break ;
				s_split[index][j] = (s + i)[j];
				j++;
			}
			index++;
			i = i + j - 1;
		}
		i++;
	}
}

static int	ft_free(char **s_split, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s_split[i] == NULL)
		{
			while (j < len)
			{
				free(s_split[j]);
				s_split[j] = NULL;
				j++;
			}
			free(s_split);
			s_split = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;
	int		s_split_size;

	s_split_size = count_word(s, c);
	s_split = malloc((s_split_size + 1) * sizeof(char *));
	if (s_split == NULL)
		return (NULL);
	s_split[s_split_size] = NULL;
	ft_word_size(s, s_split, c);
	if (ft_free(s_split, s_split_size) == 0)
		return (NULL);
	ft_filling(s, s_split, c);
	return (s_split);
}

/*int	main(void)
{
	int	i;

	i = 0;
	while (ft_split("caaccaabcbcc", 'c')[i] != NULL)
	{
		printf("%s\n", ft_split("caaccaabbccc", 'c')[i]);
		i++;
	}
}*/