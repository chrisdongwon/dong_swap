/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 21:00:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

static int	has_duplicates(int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (array[i] == array[i + 1])
			return (1);
	}
	return (0);
}

static int	*stack_to_array(t_stack *stack, int size)
{
	int		*result;
	int		i;
	t_node	*node;

	result = (int *)malloc(size * sizeof(int));
	if (!result)
		return (0);
	i = 0;
	node = stack->top;
	while (i < size)
	{
		result[i++] = node->content;
		node = node->next;
	}
	return (result);
}

t_target	*init_target(t_stack *stack)
{
	t_target	*target;

	target = (t_target *)malloc(sizeof(t_target));
	if (!target)
		flush_stack(stack, 1);
	target->a = stack;
	target->b = init_stack();
	if (!target->b)
		flush_target(target, 1);
	target->array = stack_to_array(stack, stack->size);
	if (!target->array)
		flush_target(target, 1);
	sort_array(target->array, stack->size);
	if (has_duplicates(target->array, stack->size))
		flush_target(target, 1);
	return (target);
}

void	flush_target(t_target *target, int error)
{
	if (target)
	{
		flush_stack(target->a, 0);
		flush_stack(target->b, 0);
		free(target->array);
		free(target);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
