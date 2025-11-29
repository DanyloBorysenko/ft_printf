/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danborys <borysenkodanyl@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:09:55 by danborys          #+#    #+#             */
/*   Updated: 2025/11/29 16:34:42 by danborys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_get_dig_count(unsigned long nb, unsigned long base);
char	*ft_itoa_unsd_int(unsigned int i);
char	*ft_itoa_hex(unsigned long nb, char c);
char	*ft_itoa_p(void *p);

int		ft_print_str(char *str);
int		ft_print_signed_int(int nb);
int		ft_print_unsigned_int(unsigned int nb);
int		ft_print_pointer(void *ptr);
int		ft_print_hex(unsigned int nb, char c);

#endif