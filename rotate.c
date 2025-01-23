/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:49 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 15:12:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_pushswap *param)
{
	rotate(param->a);
	ft_printf("ra\n");
}

void	rb(t_pushswap *param)
{
	rotate(param->b);
	ft_printf("rb\n");
}

void	rr(t_pushswap *param)
{
	rotate(param->a);
	rotate(param->b);
	ft_printf("rr\n");
}
