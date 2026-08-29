/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:40:20 by setilbec          #+#    #+#             */
/*   Updated: 2026/08/29 18:23:10 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	check_format(char character, va_list args)
{
	if (character == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (character == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (character == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (character == 'd')
		return (ft_print_dcml(va_arg(args, int)));
	else if (character == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (character == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (character == 'x' || character == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), character));
	else if (character == '%')
		return (ft_print_char('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	i = 0;
	total_len = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			total_len += check_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			total_len += ft_print_char(format[i]);
			i++;
		}
	}
	va_end (args);
	return (total_len);
}
