/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:39:25 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:39:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adjust_both(t_pushswap *param, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(param, true);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(param, true);
		*a = *a + 1;
		*b = *b + 1;
	}
}

static void	adjust_a(t_pushswap *param, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(param, true);
			a--;
		}
		else
		{
			rra(param, true);
			a++;
		}
	}
}

static void	adjust_b(t_pushswap *param, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(param, true);
			b--;
		}
		else
		{
			rrb(param, true);
			b++;
		}
	}
}

void	adjust(t_pushswap *param, int *a, int *b)
{
	adjust_both(param, a, b);
	adjust_a(param, *a);
	adjust_b(param, *b);
}

void	final_adjustment(t_pushswap *param)
{
	int	count;

	count = top_location(param);
	while (count)
	{
		if (count > 0)
		{
			ra(param, true);
			count--;
		}
		else
		{
			rra(param, true);
			count++;
		}
	}
}
