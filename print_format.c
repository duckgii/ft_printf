/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:18:07 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/25 18:12:24 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_itos(int n, int *return_len)
{
	long long	num;
	int			len;
	char		c;

	len = 1;
	num = (long long)n;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (0);
		num *= -1;
		(*return_len)++;
	}
	while (num / len > 9)
		len = len * 10;
	while (len >= 1)
	{
		c = (char)(num / len) + '0';
		if (write(1, &c, 1) == -1)
			return (0);
		num %= len;
		len /= 10;
		(*return_len)++;
	}
	return (1);
}

int	print_xtos(unsigned int num, int *return_len, char flag)
{
	if (flag == 'x')
		return (write_hex_x(num, return_len));
	if (flag == 'X')
		return (write_hex_bigx(num, return_len));
	return (0);
}

int	write_hex_x(unsigned int num, int *return_len)
{
	int				len;
	unsigned int	temp;

	temp = num;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len *= 16;
	}
	while (len > 0)
	{
		if (write(1, &"0123456789abcdef"[num / len], 1) == -1)
			return (0);
		(*return_len)++;
		num %= len;
		len /= 16;
	}
	return (1);
}

int	write_hex_bigx(unsigned int num, int *return_len)
{
	int				len;
	unsigned int	temp;

	temp = num;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len *= 16;
	}
	while (len > 0)
	{
		if (write(1, &"0123456789ABCDEF"[num / len], 1) == -1)
			return (0);
		(*return_len)++;
		num %= len;
		len /= 16;
	}
	return (1);
}

int	print_utos(unsigned int num, int *return_len)
{
	int		len;
	char	c;

	len = 1;
	while (num / len > 9)
		len *= 10;
	while (len >= 1)
	{
		c = num / len + '0';
		if (write(1, &c, 1) == -1)
			return (0);
		num %= len;
		len /= 10;
		(*return_len)++;
	}
	return (1);
}
