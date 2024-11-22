/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:18:02 by alpayet           #+#    #+#             */
/*   Updated: 2024/11/21 23:41:00 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	signe;

	i = 0;
	n = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+')
		&& (nptr[i + 1] >= 48 && nptr[i + 1] <= 57))
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	if (nptr[i] < 48 || nptr[i] > 57)
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = 10 * n + nptr[i] - 48;
		i++;
	}
	return (signe * n);
}

/*#include <stdlib.h>

int	main(void)
{
	printf("%d", ft_atoi("2147483648"));
}*/
