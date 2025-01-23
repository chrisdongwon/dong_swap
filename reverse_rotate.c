/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:25:59 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 19:03:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size > 1)
	{
		node = stack->bottom;
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = 0;
		stack->top->prev = node;
		node->next = stack->top;
		stack->top = node;
		node->prev = 0;
	}
}

void	rra(t_pushswap *param)
{
	reverse_rotate(param->a);
	ft_printf("rra\n");
}

void	rrb(t_pushswap *param)
{
	reverse_rotate(param->b);
	ft_printf("rrb\n");
}

void	rrr(t_pushswap *param)
{
	reverse_rotate(param->a);
	reverse_rotate(param->b);
	ft_printf("rrr\n");
}
