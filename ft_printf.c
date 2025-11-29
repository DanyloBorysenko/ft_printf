/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:51 by danborys          #+#    #+#             */
/*   Updated: 2025/11/29 16:33:03 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_arg(const char *ptr, va_list args)
{
	int	count;

	count = 0;
	if (*ptr == '%')
		count += print_char('%');
	else if (*ptr == 'c')
		count += print_char(va_arg(args, int));
	else if (*ptr == 'd' || *ptr == 'i')
		count += ft_print_signed_int(va_arg(args, int));
	else if (*ptr == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (*ptr == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (*ptr == 'x' || *ptr == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), *ptr);
	else if (*ptr == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += print_arg(str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
