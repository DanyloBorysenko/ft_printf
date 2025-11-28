/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:09:55 by danborys          #+#    #+#             */
/*   Updated: 2025/11/28 15:35:59 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *, ...);
int	get_dig_count(unsigned long nb, unsigned long base);
char	*ft_itoa_unsd_int(unsigned int i);
char	*ft_itoa_hex(unsigned long nb, size_t toupp);
char	*ft_itoa_p(void *p);

#endif