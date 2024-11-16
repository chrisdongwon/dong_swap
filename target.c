/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:27:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	flush_target(t_target *target, int error)
{
	if (target)
	{
		flush_stack(target->a, 0);
		flush_stack(target->b, 0);
		flush_stack(target->sequence, 0);
		free(target);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

t_target	*init_target(t_stack *stack)
{
	t_target	*target;

	target = (t_target *)malloc(sizeof(t_target));
	if (!target)
		flush_stack(stack, 1);
	target->a = stack;
	target->b = init_stack();
	target->sequence = init_stack();
	return (target);
}

void	print_target(t_target *target)
{
	ft_printf("[stack a]\n");
	print_stack(target->a);
	ft_printf("[stack b]\n");
	print_stack(target->b);
}

int	*stack_to_array(t_target *target, char choice, size_t size)
{
	int		*result;
	t_stack	*stack;
	int		*data;
	size_t		i;
	t_list	*node;

	if (choice == 'a')
		stack = target->a;
	else
		stack = target->b;
	result = (int *)malloc(size * sizeof(int));
	if (!result)
		return (0);
	i = -1;
	node = stack->top;
	while (++i < size)
	{
		data = node->content;
		result[i] = *data;
		node = node->next;
	}
	return (result);
}
