/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:08:09 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:34:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	flush_stack(t_stack *stack, int error)
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

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		flush_stack(stack, 1);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int n)
{
	int		*data;
	t_list	*node;

	data = (int *)malloc(sizeof(int));
	if (data)
	{
		*data = n;
		node = ft_lstnew(data);
		if (node)
		{
			ft_lstadd_front(&(stack->top), node);
			stack->size++;
			if (stack->size == 1)
				stack->bottom = stack->top;
		}
	}
}

int	*pop(t_stack *stack)
{
	int		*result;
	t_list	*node;

	result = 0;
	node = stack->top;
	if (node)
	{
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
	t_list	*node;
	int		*data;

	node = stack->top;
	if (!node)
	{
		ft_printf("empty stack\n");
		return ;
	}
	while (node)
	{
		data = node->content;
		ft_printf("%d\n", *data);
		node = node->next;
	}
}
