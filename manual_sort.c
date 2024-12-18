/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:29:58 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 11:14:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_count(t_stack *stack, int pivot)
{
	int		result;
	t_node	*node;

	result = 0;
	node = stack->top;
	while (node)
	{
		if (node->content < pivot)
			result++;
		node = node->next;
	}
	return (result);
}

static void	sort_two(t_target *target)
{
	if (target->a->top->content > target->a->top->next->content)
		sa(target, 1);
}

static void	sort_three(t_target *target)
{
	int	a[3];

	a[0] = target->a->top->content;
	a[1] = target->a->top->next->content;
	a[2] = target->a->top->next->next->content;
	if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(target, 1);
		ra(target, 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(target, 1);
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(target, 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		rra(target, 1);
	else
	{
		sa(target, 1);
		rra(target, 1);
	}
}

static void	sort_four_five(t_target *target)
{
	int	pivot;
	int	count;

	pivot = target->array[target->a->size / 2];
	count = push_count(target->a, pivot);
	while (count)
	{
		if (target->a->top->content < pivot)
		{
			pb(target, 1);
			count--;
		}
		else
			ra(target, 1);
	}
	if (target->a->size == 2)
		sort_two(target);
	else
		sort_three(target);
	if (is_sorted(target->b))
		sb(target, 1);
	pa(target, 1);
	pa(target, 1);
}

void	manual_sort(t_target *target)
{
	if (target->a->size == 2)
		sort_two(target);
	else if (target->a->size == 3)
		sort_three(target);
	else
		sort_four_five(target);
}
