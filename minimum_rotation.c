/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:11:14 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 21:52:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_ab(t_target *target, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rr(target);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(target);
		(*a)++;
		(*b)++;
	}
}

static void	rotate_a(t_target *target, int a)
{
	while (a > 0)
	{
		ra(target);
		a--;
	}
	while (a < 0)
	{
		rra(target);
		a++;
	}
}

static void	rotate_b(t_target *target, int b)
{
	while (b > 0)
	{
		rb(target);
		b--;
	}
	while (b < 0)
	{
		rrb(target);
		b++;
	}
}

static void	find_minimum_rotation(t_target *target, int *a, int *b)
{
	int		a_temp;
	int		b_temp;
	int		i;
	t_node	*node;

	i = -1;
	node = target->b->top;
	while (++i < target->b->size)
	{
		a_temp = best_location(target, node->content);
		b_temp = i;
		if (i > target->b->size / 2)
			b_temp = (target->b->size - i) * -1;
		if (!i || ft_abs(a_temp) + ft_abs(b_temp) < ft_abs(*a) + ft_abs(*b))
		{
			*a = a_temp;
			*b = b_temp;
		}
		node = node->next;
	}
}

void	minimum_rotation(t_target *target)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	find_minimum_rotation(target, &a, &b);
	rotate_ab(target, &a, &b);
	rotate_a(target, a);
	rotate_b(target, b);
}
