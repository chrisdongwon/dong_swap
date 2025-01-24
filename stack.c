/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:22 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 11:06:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	push(t_stack *stack, int data)
{
	if (!insert(&(stack->top), data))
		return (false);
	stack->size++;
	if (stack->size == 1)
		stack->bottom = stack->top;
	return (true);
}

int	pop(t_stack *stack)
{
	int	result;

	result = stack->top->data;
	remove(&(stack->top));
	stack->size--;
	if (!(stack->top))
		stack->bottom = 0;
	return (result);
}

t_stack	*new_stack(void)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(t_stack));
	if (!result)
		return (0);
	result->top = 0;
	result->bottom = 0;
	result->size = 0;
	return (result);
}

void	free_stack(t_stack *stack)
{
	free_list(&(stack->top));
	free(stack);
}

int	stack_extremum(t_stack *stack, int (*comparator)(int, int))
{
	int		result;
	t_node	*node;

	node = stack->top;
	result = node->data;
	while (node)
	{
		if (comparator(node->data, result))
			result = node->data;
		node = node->next;
	}
	return (result);
}
