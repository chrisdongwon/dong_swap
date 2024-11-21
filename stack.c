/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:08:09 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 18:15:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
	return (stack);
}

void	flush_stack(t_stack *stack, int error)
{
	if (stack)
	{
		flush_list(&(stack->top));
		free(stack);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	push(t_stack *stack, int n)
{
	t_node	*node;

	node = new_node();
	if (!node)
		return (0);
	node->content = n;
	add_node(&(stack->top), node);
	stack->size++;
	if (stack->size == 1)
		stack->bottom = stack->top;
	return (1);
}

// precondition: stack-size > 0
int	pop(t_stack *stack)
{
	int		result;
	t_node	*node;

	result = 0;
	if (stack && stack->size)
	{
		node = stack->top;
		result = node->content;
		stack->top = node->next;
		free(node);
		node = 0;
		stack->size--;
		if (!stack->size)
			stack->bottom = 0;
	}
	return (result);
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node)
	{
		ft_printf("Empty\n");
		return ;
	}
	while (node)
	{
		ft_printf("%d\n", node->content);
		node = node->next;
	}
}
