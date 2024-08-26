/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:20:51 by edforte           #+#    #+#             */
/*   Updated: 2024/08/21 18:25:48 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arguments(char type, va_list argp)
{
	int	i;

	i = 0;
	if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'c')
		return (ft_putchar(va_arg(argp, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(argp, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(argp, int)));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;

	i = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			i += print_arguments(*format, argp);
		}
		else
			i += ft_putchar(*format);
		format ++;
	}
	va_end(argp);
	return (i);
}
