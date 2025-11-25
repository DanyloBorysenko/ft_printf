/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:51 by danborys          #+#    #+#             */
/*   Updated: 2025/11/25 14:11:30 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

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
			else if (*str == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				count++;				
			}
			else if (*str == 's')
			{
				str_arg = va_arg(args, char*);
				if (!str_arg)
					str_arg = "(null)";
				ft_putstr_fd(str_arg, 1);
				count += ft_strlen(str_arg);
			}
			else if (*str == 'd' || *str == 'i')
			{
				str_arg = ft_itoa(va_arg(args, int));
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
			}
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
