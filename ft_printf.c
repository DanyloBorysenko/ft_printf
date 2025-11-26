/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:51 by danborys          #+#    #+#             */
/*   Updated: 2025/11/26 18:07:30 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

char	*ft_itoa_unsd_int(unsigned int i)
{
	unsigned int	nb;
	int				chars_count;
	char			*ptr;

	nb = i;
	chars_count = 1;
	while (nb >= 10)
	{
		chars_count++;
		nb = nb / 10;
	}
	ptr = malloc(sizeof(char) * (chars_count + 1));
	if (!ptr)
		return (NULL);
	ptr[chars_count] = '\0';
	chars_count--;
	while (chars_count >= 0)
	{
		ptr[chars_count] = (i % 10) + '0';
		i = i / 10;
		chars_count--;
	}
	return (ptr);
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
			else if (*str == 'u')
			{
				str_arg = ft_itoa_unsd_int(va_arg(args, unsigned int));
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
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
