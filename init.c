/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:29:10 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 12:03:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_array(t_pushswap *param, int argc, char **argv)
{
	size_t	i;

	param->array_size = argc - 1;
	param->array = (int *)malloc(param->array_size * sizeof(int));
	if (!param->array)
		flush_pushswap(param, true);
	i = 0;
	while (i < param->array_size)
	{
		if (!ft_isinteger(argv[i + 1]))
			flush_pushswap(param, true);
		param->array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

static void	init_stack(t_pushswap *param)
{
	size_t	i;

	param->a = new_stack();
	if (!param->a)
		flush_pushswap(param, true);
	i = param->array_size;
	while (i)
		push(param->a, param->array[--i]);
	param->b = new_stack();
	if (!param->b)
		flush_pushswap(param, true);
}

void	init_pushswap(t_pushswap *param, int argc, char **argv)
{
	param->array = 0;
	param->a = 0;
	param->b = 0;
	init_array(param, argc, argv);
	init_stack(param);
	sort_array(param);
}
