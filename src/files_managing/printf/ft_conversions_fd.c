/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:11:58 by alpayet           #+#    #+#             */
/*   Updated: 2025/10/08 01:56:01 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_ul_fd(unsigned long nbr, char *base, int fd);

int	ft_conversions_s_fd(va_list args, int fd)
{
	char	*str;

	str = va_arg(args, void *);
	if (str == NULL)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(str, fd));
}

int	ft_conversions_d_or_i_fd(va_list args, int fd)
{
	long	nbr;

	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		return (ft_putnbr_base_ul_fd(-nbr, "0123456789", fd) + 1);
	}
	return (ft_putnbr_base_ul_fd(nbr, "0123456789", fd));
}

int	ft_conversions_u_fd(va_list args, int fd)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (ft_putnbr_base_ul_fd(nbr, "0123456789", fd));
}

int	ft_conversions_x_or_upperx_fd(char format_char, va_list args, int fd)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (format_char == 'x')
		return (ft_putnbr_base_ul_fd(nbr, "0123456789abcdef", fd));
	return (ft_putnbr_base_ul_fd(nbr, "0123456789ABCDEF", fd));
}

int	ft_conversions_p_fd(va_list args, int fd)
{
	void	*addr;

	addr = va_arg(args, void *);
	if (addr == NULL)
		return (ft_putstr_fd("(nil)", fd));
	if (ft_putstr_fd("0x", fd) == -1)
		return (-1);
	return (ft_putnbr_base_ul_fd((unsigned long)addr, "0123456789abcdef", fd)
		+ 2);
}
