/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:46:34 by danborys          #+#    #+#             */
/*   Updated: 2025/11/29 16:34:03 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_dig_count(unsigned long nb, unsigned long base)
{
	int	digits_count;

	digits_count = 1;
	while (nb >= base)
	{
		digits_count++;
		nb = nb / base;
	}
	return (digits_count);
}

char	*ft_itoa_unsd_int(unsigned int i)
{
	int				chars_count;
	char			*ptr;

	chars_count = ft_get_dig_count(i, 10);
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

char	*ft_itoa_hex(unsigned long nb, char c)
{
	char			*hex_low;
	char			*hex_up;
	unsigned long	j;
	int				chars_count;
	char			*ptr;

	j = nb;
	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	chars_count = ft_get_dig_count(nb, 16);
	ptr = malloc(sizeof(char) * (chars_count + 1));
	if (!ptr)
		return (NULL);
	ptr[chars_count] = '\0';
	chars_count--;
	while (chars_count >= 0)
	{
		if (c == 'X')
			ptr[chars_count] = hex_up[j % 16];
		else
			ptr[chars_count] = hex_low[j % 16];
		chars_count--;
		j = j / 16;
	}
	return (ptr);
}

char	*ft_itoa_p(void *p)
{
	unsigned long	j;
	char			*hex;
	char			*suff;
	char			*res;

	if (p == NULL)
		return (ft_strdup("(nil)"));
	suff = "0x";
	j = (unsigned long) p;
	hex = ft_itoa_hex(j, 0);
	if (!hex)
		return (NULL);
	res = ft_strjoin(suff, hex);
	free(hex);
	return (res);
}
