/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:43:42 by edforte           #+#    #+#             */
/*   Updated: 2024/08/20 14:16:50 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digcount(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i ++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i ++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	res;

	if (nb == -2147483648)
	{
		res = write(1, "-2147483648", 11);
		(void)res;
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
	return (digcount(nb));
}
