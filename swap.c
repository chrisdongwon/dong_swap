/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:55:10 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:36:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_stack *stack)
{
	int	first;
	int	second;

	if (stack->size > 1)
	{
		first = pop(stack);
		second = pop(stack);
		if (!push(stack, first))
			return (false);
		if (!push(stack, second))
			return (false);
	}
	return (true);
}

void	sa(t_pushswap *param, bool print)
{
	if (!swap(param->a))
		return (flush_pushswap(param, true));
	if (print)
		ft_printf("sa\n");
}

void	sb(t_pushswap *param, bool print)
{
	if (!swap(param->b))
		return (flush_pushswap(param, true));
	if (print)
		ft_printf("sb\n");
}

void	ss(t_pushswap *param, bool print)
{
	if (!swap(param->a))
		return (flush_pushswap(param, true));
	if (!swap(param->b))
		return (flush_pushswap(param, true));
	if (print)
		ft_printf("ss\n");
}
