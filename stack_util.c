/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:10:21 by cwon              #+#    #+#             */
/*   Updated: 2024/11/24 17:12:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*set_data(int argc, char **argv)
{
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		flush_stack(stack, 1);
	while (--argc)
	{
		if (!ft_isinteger(argv[argc]))
			flush_stack(stack, 1);
		if (!push(stack, ft_atoi(argv[argc])))
			flush_stack(stack, 1);
	}
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	stack_extremum(t_stack *stack, int (*comparator)(int, int))
{
	int		result;
	t_node	*node;

	node = stack->top;
	result = node->content;
	while (node)
	{
		if (comparator(node->content, result))
			result = node->content;
		node = node->next;
	}
	return (result);
}
