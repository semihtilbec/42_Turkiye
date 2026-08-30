/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:33:19 by setilbec          #+#    #+#             */
/*   Updated: 2026/08/30 16:30:33 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	count = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	address = (unsigned long long)ptr;
	count += ft_print_hex(address, 'x');
	return (count);
}
