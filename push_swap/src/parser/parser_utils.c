/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:58:21 by setilbec          #+#    #+#             */
/*   Updated: 2026/09/19 15:09:15 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parser_error(t_data *data)
{
	stack_clear(&data->a);
	stack_clear(&data->b);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_bench_flag(char *str)
{
	int		i;
	char	*bench;

	bench = "--bench";
	i = 0;
	while (str[i] && bench[i] && str[i] == bench[i])
		i++;
	if (str[i] == '\0' && bench[i] == '\0')
		return (1);
	return (0);
}

int	has_duplicate(t_stack *stack, int nbr)
{
	
}
