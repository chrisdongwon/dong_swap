/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:42:09 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 19:18:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_pushswap *param)
{
	int	top;
	int	mid;
	int	bot;

	top = param->a->top->data;
	mid = param->a->top->next->data;
	bot = param->a->top->next->next->data;
	if (top > mid && mid > bot && top > bot)
	{
		sa(param);
		rra(param);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(param);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(param);
		ra(param);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(param);
	else if (mid > top && mid > bot && top > bot)
		rra(param);
}

static void	greedy_insertion_sort(t_pushswap *param)
{
	int	a_rotation;
	int	b_rotation;

	tripartition(param);
	while (param->a->size > 3)
		pb(param);
	if (param->a->size == 2 && param->a->top->data > param->a->top->next->data)
		sa(param);
	if (param->a->size == 3)
		sort_three(param);
	while (param->b->size)
	{
		a_rotation = 0;
		b_rotation = 0;
		get_minimum_rotation(param, &a_rotation, &b_rotation);
		adjust(param, &a_rotation, &b_rotation);
		pa(param);
	}
	final_adjustment(param);
}

int	main(int argc, char **argv)
{
	t_pushswap	param;

	if (argc > 1)
	{
		init_pushswap(&param, argc, argv);
		if (!is_sorted(param.a->top))
		{
			if (param.a->size == 2)
				sa(&param);
			else if (param.a->size == 3)
				sort_three(&param);
			else
				greedy_insertion_sort(&param);
		}
		flush_pushswap(&param, false);
	}
	return (0);
}
