/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 13:06:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

int	init_target(t_target *target, t_stack *stack)
{
	target->a = stack;
	target->b = (t_stack *)malloc(sizeof(t_stack));
	if (!target->b)
		return (0);
	init_stack(target->b);
	return (1);
}

void	flush_target(t_target *target, int error)
{
	if (error)
		ft_putstr_fd("Error\n", 2);
	if (target)
	{
		flush_stack(target->a, 0);
		flush_stack(target->b, 0);
	}
	free(target);
}

void	print_target(t_target *target)
{
	ft_printf("[stack a]\n");
	print_stack(target->a);
	ft_printf("[stack b]\n");
	print_stack(target->b);
}
int	is_sorted(t_target *target, char choice, size_t size)
{
	t_list	*node;
	t_stack	*stack;
	int		*data;
	int		*next_data;
	size_t	i;

	if (choice == 'a')
		stack = target->a;
	else
		stack = target->b;
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
