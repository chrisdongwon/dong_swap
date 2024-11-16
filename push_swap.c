/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:07 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:29:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int n)
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

t_stack	*set_data(int argc, char **argv)
{
	t_stack	*stack;
 	size_t	i;
	int		data;

	stack = init_stack();
	i = argc;
	while (--i)
	{
		if (!ft_isinteger(argv[i]))
			flush_stack(stack, 1);
		data = ft_atoi(argv[i]);
		if (is_duplicate(stack, data))
			flush_stack(stack, 1);
		push(stack, data);
	}
	return (stack);
}

int	is_sorted(t_stack *stack, size_t size)
{
	t_list	*node;
	int		*data;
	int		*next_data;
	size_t	i;

	i = 0;
	node = stack->top;
	while (node && i < size)
	{
		data = node->content;
		if (!node->next)
			return (1);
		next_data = (node->next)->content;
		if (*data > *next_data)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	t_stack		*stack;
	t_target	*target;

	stack = set_data(argc, argv);
	target = init_target(stack);
	sort(target);
	// post-sort optimization of sequences
	print_sequence(target);
}
