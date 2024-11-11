/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:22:08 by cwon              #+#    #+#             */
/*   Updated: 2024/11/11 12:18:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_target *target)
{
	t_list	*node;
	int		*data;
	int		*next_data;

	if (target->b->size)
		return (0);
	node = target->a->top;
	while (node)
	{
		data = node->content;
		if (!node->next)
			return (1);
		next_data = (node->next)->content;
		if (*data > *next_data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	*stack_to_array(t_target *target, int n)
{
	int		*result;
	t_stack	*stack;
	int		*data;
	int		i;
	t_list	*node;

	stack = target->a;
	result = (int *)malloc(n * sizeof(int));
	if (!result)
		return (0);
	i = -1;
	node = stack->top;
	while (++i < n)
	{
		data = node->content;
		result[i] = *data;
		node = node->next;
	}
	return (result);
}

void	sort(t_target *target)
{
	if (is_sorted(target))
		return ;
	if (target->a->size == 2)
		sa(target);
	else if (target->a->size == 3)
		sort_three(target);
}
