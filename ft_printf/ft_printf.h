/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edforte <edforte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:52:54 by edforte           #+#    #+#             */
/*   Updated: 2024/02/06 15:54:48 by edforte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(char num);
int	ft_put_upp_hex(unsigned int num, char *digits);
int	ft_put_low_hex(unsigned int num, char *digits);
int	ft_pointer(unsigned long int num, char *digits);
int	ft_put_uns_nbr(unsigned int nb);
int	ft_putnbr(int nb);

#endif