/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:57:53 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 13:03:44 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*node;

	if (stack->size >= 2)
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

void	rra(t_target *target)
{
	ft_printf("rra\n");
	reverse_rotate(target->a);
}

void	rrb(t_target *target)
{
	ft_printf("rrb\n");
	reverse_rotate(target->b);
}

void	rrr(t_target *target)
{
	ft_printf("rrr\n");
	reverse_rotate(target->a);
	reverse_rotate(target->b);
}
