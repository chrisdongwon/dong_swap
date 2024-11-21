/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 15:26:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

static void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size > 1)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->top->prev = 0;
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
		node->next = 0;
	}
}

void	ra(t_target *target)
{
	rotate(target->a);
	ft_printf("ra\n");
}

void	rb(t_target *target)
{
	rotate(target->b);
	ft_printf("rb\n");
}

void	rr(t_target *target)
{
	rotate(target->a);
	rotate(target->b);
	ft_printf("rr\n");
}
