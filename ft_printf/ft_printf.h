/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:56:29 by setilbec          #+#    #+#             */
/*   Updated: 2026/08/30 16:39:28 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_hex(unsigned long long n, char format);
int	ft_print_nbr(int n);
int	ft_print_ptr(void *ptr);
int	ft_print_str(char *str);
int	ft_print_unsigned(unsigned int n);

#endif
