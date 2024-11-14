/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:34 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 13:03:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	swap(t_stack *stack)
{
	int	*first;
	int	*second;

	if (stack->size >= 2)
	{
		first = pop(stack);
		second = pop(stack);
		push(stack, *first);
		push(stack, *second);
		free(first);
		free(second);
	}
}

void	sa(t_target *target)
{
	ft_printf("sa\n");
	swap(target->a);
}

void	sb(t_target *target)
{
	ft_printf("sb\n");
	swap(target->b);
}

void	ss(t_target *target)
{
	ft_printf("ss\n");
	swap(target->a);
	swap(target->b);
}
