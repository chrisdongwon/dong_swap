/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/09 20:16:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	rotate(t_stack *stack)
{
	t_list	*node;

	if (stack->size >= 2)
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
}

void	rb(t_target *target)
{
	rotate(target->b);
}

void	rr(t_target *target)
{
	rotate(target->a);
	rotate(target->b);
}
