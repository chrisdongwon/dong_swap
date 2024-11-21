/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_location.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:07:34 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 22:00:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	middle_location(t_target *target, int data)
{
	int		result;
	t_node	*node;

	node = target->a->top;
	result = 1;
	while (node->next && !(node->content < data && data < node->next->content))
	{
		result++;
		node = node->next;
	}
	if (result > target->a->size / 2)
		result = (target->a->size - result) * -1;
	return (result);
}

int	top_bottom_location(t_target *target, int extremum, int is_top)
{
	int		result;
	t_node	*node;

	result = 0;
	node = target->a->top;
	while (node && node->content != extremum)
	{
		result++;
		node = node->next;
	}
	result += is_top;
	if (result > target->a->size / 2)
		result = (target->a->size - result) * -1;
	return (result);
}

int	best_location(t_target *target, int data)
{
	int	minimum;
	int	maximum;

	minimum = stack_extremum(target->a, ft_less_than);
	maximum = stack_extremum(target->a, ft_greater_than);
	if (data < minimum)
		return (top_bottom_location(target, minimum, 0));
	if (data > maximum)
		return (top_bottom_location(target, maximum, 1));
	return (middle_location(target, data));
}
