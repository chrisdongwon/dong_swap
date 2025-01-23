/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:56 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 19:18:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_location(t_pushswap *param)
{
	int		count;
	int		stack_min;
	t_node	*node;

	stack_min = stack_extremum(param->a, ft_less_than);
	count = 0;
	node = param->a->top;
	while (node && node->data != stack_min)
	{
		node = node->next;
		count++;
	}
	if (count >= (int)param->a->size / 2)
		count = (param->a->size - count) * -1;
	return (count);
}

static int	bottom_location(t_pushswap *param)
{
	int		count;
	int		stack_max;
	t_node	*node;

	stack_max = stack_extremum(param->a, ft_greater_than);
	count = 0;
	node = param->a->top;
	while (node && node->data != stack_max)
	{
		count++;
		node = node->next;
	}
	count++;
	if (count >= (int)param->a->size / 2)
		count = (param->a->size - count) * -1;
	return (count);
}

static int	middle_location(t_pushswap *param, int data)
{
	int		count;
	t_node	*node;

	node = param->a->top;
	count = 1;
	while (node->next && !(data > node->data && data < node->next->data))
	{
		count++;
		node = node->next;
	}
	if (count > (int)param->a->size / 2)
		count = (param->a->size - count) * -1;
	return (count);
}

static int	get_a_location(t_pushswap *param, int data)
{
	if (data < stack_extremum(param->a, ft_less_than))
		return (top_location(param));
	else if (data > stack_extremum(param->a, ft_greater_than))
		return (bottom_location(param));
	return (middle_location(param, data));
}

void	get_minimum_rotation(t_pushswap *param, int *a, int *b)
{
	int		temp_a;
	int		temp_b;
	size_t	count;
	t_node	*node;

	node = param->b->top;
	count = 0;
	while (count < param->b->size)
	{
		temp_a = get_a_location(param, node->data);
		temp_b = count;
		if (count >= param->b->size / 2)
			temp_b = (param->b->size - count) * -1;
		if (!count || ft_abs(temp_a) + ft_abs(temp_b) < ft_abs(*a) + ft_abs(*b))
		{
			*a = temp_a;
			*b = temp_b;
		}
		node = node->next;
		count++;
	}
}
