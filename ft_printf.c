/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:50:51 by danborys          #+#    #+#             */
/*   Updated: 2025/11/27 18:41:58 by danborys         ###   ########.fr       */
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

char	*ft_itoa_hex(int nb, size_t toupp)
{
	unsigned int	i;
	unsigned int	j;
	int	chars_count;
	char *ptr;
	int	rem;

	i = (unsigned int) nb;
	j = (unsigned int) nb;
	chars_count = 1;
	while (i >= 16)
	{
		chars_count++;
		i = i / 16;
	}
	ptr = malloc(sizeof(char) * (chars_count + 1));
	ptr[chars_count] = '\0';
	chars_count--;
	while (chars_count >= 0)
	{
		rem = j % 16;
		if (rem <= 9)
			ptr[chars_count] = rem + '0';
		else
		{
			if (toupp == 1)
				ptr[chars_count] = rem + '7';
			else
			{
				ptr[chars_count] = rem + 'W';
			}
		}
		chars_count--;
		j = j / 16;
	}
	return (ptr);
}

char	*ft_itoa_p(void *p)
{
	unsigned long	i;
	unsigned long	j;
	int				chars_count;
	char			*ptr;
	unsigned int	rem;
	int				pos;

	i = (unsigned long) p;
	j = (unsigned long) p;
	chars_count = 1;
	while (i >= 16)
	{
		chars_count++;
		i = i / 16;
	}
	ptr = malloc(sizeof(char) * (chars_count + 3));
	if (!ptr)
		return (NULL);
	ptr[chars_count + 2] = '\0';
	ptr[0] = '0';
	ptr[1] = 'x';
	pos = chars_count + 1;
	while (pos >= 2)
	{
		rem = j % 16;
		if (rem >= 10)
			ptr[pos] = rem - 10 + 'a';
		else
			ptr[pos] = rem + '0';

		j = j / 16;
		pos--;
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
			else if (*str == 'x')
			{
				str_arg = ft_itoa_hex(va_arg(args, int), 0);
				count += ft_strlen(str_arg);
				ft_putstr_fd(str_arg, 1);
				free(str_arg);
			}
			else if (*str == 'X')
			{
				str_arg = ft_itoa_hex(va_arg(args, int), 1);
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
