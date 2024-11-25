/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:45:11 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 09:53:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation_stack_bonus.h"

t_op_stack	*init_operation_stack(void)
{
	t_op_stack	*stack;

	stack = (t_op_stack *)malloc(sizeof(t_op_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
	return (stack);
}

void	flush_operation_stack(t_op_stack *stack, int error)
{
	if (stack)
	{
		ft_lstclear(&(stack->top), free);
		free(stack);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	push_operation(t_op_stack *stack, char *str)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
		return (0);
	ft_lstadd_front(&(stack->top), node);
	stack->size++;
	if (stack->size == 1)
		stack->bottom = stack->top;
	return (1);
}
