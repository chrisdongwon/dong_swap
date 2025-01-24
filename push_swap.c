/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:42:09 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:40:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_pushswap(t_pushswap *param, bool error)
{
	if (param->array)
		free(param->array);
	if (param->a)
		free_stack(param->a);
	if (param->b)
		free_stack(param->b);
	if (error)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static void	tripartition(t_pushswap *param)
{
	int		low_pivot;
	int		high_pivot;
	size_t	count;

	low_pivot = param->array[param->a->size / 3];
	high_pivot = param->array[param->a->size * 2 / 3];
	count = param->a->size;
	while (count)
	{
		if (param->a->top->data < low_pivot)
		{
			pb(param, true);
			rb(param, true);
		}
		else if (param->a->top->data < high_pivot)
			pb(param, true);
		else
			ra(param, true);
		count--;
	}
}

static void	sort_three(t_pushswap *param)
{
	int	top;
	int	middle;
	int	bottom;

	top = param->a->top->data;
	middle = param->a->top->next->data;
	bottom = param->a->top->next->next->data;
	if (top > middle && middle > bottom && top > bottom)
	{
		sa(param, true);
		rra(param, true);
	}
	else if (top > middle && bottom > middle && top > bottom)
		ra(param, true);
	else if (middle > top && middle > bottom && bottom > top)
	{
		sa(param, true);
		ra(param, true);
	}
	else if (top > middle && bottom > middle && bottom > top)
		sa(param, true);
	else if (middle > top && middle > bottom && top > bottom)
		rra(param, true);
}

static void	greedy_insertion_sort(t_pushswap *param)
{
	int	a_rotation;
	int	b_rotation;

	tripartition(param);
	while (param->a->size > 3)
		pb(param, true);
	if (param->a->size == 2 && param->a->top->data > param->a->top->next->data)
		sa(param, true);
	if (param->a->size == 3)
		sort_three(param);
	while (param->b->size)
	{
		a_rotation = 0;
		b_rotation = 0;
		get_minimum_rotation(param, &a_rotation, &b_rotation);
		adjust(param, &a_rotation, &b_rotation);
		pa(param, true);
	}
	final_adjustment(param);
}

void	push_swap(int argc, char **argv)
{
	t_pushswap	param;

	init_pushswap(&param, argc, argv);
	if (!is_sorted(param.a->top))
	{
		if (param.a->size == 2)
			sa(&param, true);
		else if (param.a->size == 3)
			sort_three(&param);
		else
			greedy_insertion_sort(&param);
	}
	flush_pushswap(&param, false);
}
