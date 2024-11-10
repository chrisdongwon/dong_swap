/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/10 13:42:17 by cwon             ###   ########.fr       */
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
	ft_printf("ra\n");
	rotate(target->a);
}

void	rb(t_target *target)
{
	ft_printf("rb\n");
	rotate(target->b);
}

void	rr(t_target *target)
{
	ft_printf("rr\n");
	rotate(target->a);
	rotate(target->b);
}
