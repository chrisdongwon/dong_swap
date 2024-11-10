/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:08:09 by cwon              #+#    #+#             */
/*   Updated: 2024/11/10 16:35:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_stack(t_stack *stack)
{
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
}

void	flush_stack(t_stack *stack, int error)
{
	if (error)
		ft_printf("Error\n");
	if (stack)
		ft_lstclear(&(stack->top), free);
	free(stack);
}

void	push(t_stack *stack, int n)
{
	int		*data;
	t_list	*node;

	data = (int *)malloc(sizeof(int));
	*data = n;
	node = ft_lstnew(data);
	ft_lstadd_front(&(stack->top), node);
	stack->size++;
	if (stack->size == 1)
		stack->bottom = stack->top;
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
