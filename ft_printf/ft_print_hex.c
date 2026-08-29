/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:44:25 by setilbec          #+#    #+#             */
/*   Updated: 2026/08/29 19:12:14 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hex(unsigned long long n)
{
	int	count;
	int	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_ptr_hex(n / 16);
	count += ft_print_char(base[n % 16]);
	return (count);
}
