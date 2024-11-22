/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:07 by cwon              #+#    #+#             */
/*   Updated: 2024/11/22 07:56:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*set_data(int argc, char **argv)
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

void	push_swap(int argc, char **argv)
{
	t_stack		*stack;
	t_target	*target;

	stack = set_data(argc, argv);
	target = init_target(stack);
	if (!is_sorted(target->a))
		sort(target);
	if (!is_sorted(target->a))
		flush_target(target, 1);
	flush_target(target, 0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
