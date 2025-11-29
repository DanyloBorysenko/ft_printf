/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:54 by danborys          #+#    #+#             */
/*   Updated: 2025/11/29 16:32:30 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_signed_int(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_print_unsigned_int(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_itoa_unsd_int(nb);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	char	*str;
	int		len;

	str = ft_itoa_p(ptr);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_print_hex(unsigned int nb, char c)
{
	char	*str;
	int		len;

	str = ft_itoa_hex(nb, c);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
