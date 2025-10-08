/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:52:03 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:56:27 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	str_len;

	str_len = ft_putstr_fd(s, fd);
	if (str_len == -1 || write(fd, "\n", 1) == -1)
		return (-1);
	return (str_len + 1);
}
