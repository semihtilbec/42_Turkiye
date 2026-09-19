/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:11:11 by setilbec          #+#    #+#             */
/*   Updated: 2026/09/19 14:12:06 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "operations/operations.h"
/*check*/
int		is_valid_number(char *str);

/*utils*/
void	free_stack(t_stack **stack);
void	parser_error(t_stack **a);

#endif