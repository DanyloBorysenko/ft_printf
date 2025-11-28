/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:51 by danborys          #+#    #+#             */
/*   Updated: 2025/11/28 16:30:45 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	print_signed_int(int nb)
{
	char 	*str;
	int		len;
	
	str = ft_itoa(nb);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

static int print_unsigned_int(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_itoa_unsd_int(nb);
	len = ft_strlen(str);
	free(str);
	return(len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;
	char *str_arg;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}
			else if (*str == 'x')
			{
				str_arg = ft_itoa_hex(va_arg(args, unsigned int), 0);
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
			}
			else if (*str == 'X')
			{
				str_arg = ft_itoa_hex(va_arg(args, unsigned int), 1);
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
			}
			else if (*str == 'p')
			{
				str_arg = ft_itoa_p(va_arg(args, void *));
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
			}
			else if (*str == 'u')
				count += print_unsigned_int(va_arg(args, unsigned int));
			else if (*str == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				count++;
			}
			else if (*str == 's')
				count += print_str(va_arg(args, char *));
			else if (*str == 'd' || *str == 'i')
				count += print_signed_int(va_arg(args, int));
			str++;
			continue;
		}
		ft_putchar_fd(*str, 1);
		count++;
		str++;
	}
	va_end(args);
	return (count);
}
