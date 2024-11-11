/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:07 by cwon              #+#    #+#             */
/*   Updated: 2024/11/11 12:33:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_stack *stack, int n)
{
	t_list	*node;
	int		*data;

	if (!stack->size)
		return (0);
	node = stack->top;
	while (node)
	{
		data = node->content;
		if (*data == n)
			return (1);
		node = node->next;
	}
	return (0);
}

static int	get_stack(t_stack *stack, int argc, char **argv)
{
	int		data;
	size_t	i;

	init_stack(stack);
	i = argc;
	while (--i)
	{
		if (!ft_isinteger(argv[i]))
			return (0);
		data = ft_atoi(argv[i]);
		if (is_duplicate(stack, data))
			return (0);
		push(stack, data);
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	t_stack		*stack;
	t_target	*target;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack || !get_stack(stack, argc, argv))
		return (flush_stack(stack, 1));
	target = (t_target *)malloc(sizeof(t_target));
	if (!target || !init_target(target, stack))
		return (flush_target(target, 1));
	sort(target);
	print_target(target);
	flush_target(target, 0);
}
