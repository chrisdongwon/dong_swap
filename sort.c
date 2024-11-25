/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:12 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 10:20:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition(t_target *target)
{
	int	i;
	int	pivot[2];

	i = target->a->size;
	pivot[0] = target->array[i / 3];
	pivot[1] = target->array[i * 2 / 3];
	while (i)
	{
		if (target->a->top->content < pivot[0])
		{
			pb(target, 1);
			rb(target, 1);
		}
		else if (target->a->top->content < pivot[1])
			pb(target, 1);
		else
			ra(target, 1);
		i--;
	}
}

static void	minimum_to_top(t_target *target)
{
	int	minimum;
	int	minimum_location;

	minimum = stack_extremum(target->a, ft_less_than);
	minimum_location = top_bottom_location(target, minimum, 0);
	while (minimum_location > 0)
	{
		ra(target, 1);
		minimum_location--;
	}
	while (minimum_location < 0)
	{
		rra(target, 1);
		minimum_location++;
	}
}

static void	sort_target(t_target *target)
{
	partition(target);
	while (target->a->size > 3)
		pb(target, 1);
	manual_sort(target);
	while (target->b->size)
	{
		minimum_rotation(target);
		pa(target, 1);
	}
	minimum_to_top(target);
}

void	sort(t_target *target)
{
	if (target->a->size <= 5)
		manual_sort(target);
	else
		sort_target(target);
}
