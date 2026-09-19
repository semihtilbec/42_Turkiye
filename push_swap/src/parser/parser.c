/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: setilbec <setilbec@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:07:26 by setilbec          #+#    #+#             */
/*   Updated: 2026/09/19 15:15:36 by setilbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_data *data, int argc, char **argv)
{
	int		i;
	long	nbr;
	t_node	*node;

	i = 1;
	data->output_mode = OUTPUT_OPERATIONS;
	while (i < argc)
	{
		if (is_bench_flag(argv[i]))
		{
			data->output_mode = OUTPUT_BENCH;
			i++;
			continue ;
		}
		if (!is_valid_number(argv[i]))
			parser_error(data);
	}
}
