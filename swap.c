/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:34 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 10:19:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

static int	swap(t_stack *stack)
{
	int	first;
	int	second;

	if (stack->size > 1)
	{
		first = pop(stack);
		second = pop(stack);
		if (!push(stack, first))
			return (0);
		if (!push(stack, second))
			return (0);
	}
	return (1);
}

void	sa(t_target *target, int print)
{
	if (!swap(target->a))
		return (flush_target(target, 1));
	if (print)
		ft_printf("sa\n");
}

void	sb(t_target *target, int print)
{
	if (!swap(target->b))
		return (flush_target(target, 1));
	if (print)
		ft_printf("sb\n");
}

void	ss(t_target *target, int print)
{
	if (!swap(target->a))
		return (flush_target(target, 1));
	if (!swap(target->b))
		return (flush_target(target, 1));
	if (print)
		ft_printf("ss\n");
}
