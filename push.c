/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:08:55 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:37:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *param, bool print)
{
	if (param->b->size)
	{
		if (!push(param->a, pop(param->b)))
			return (flush_pushswap(param, true));
		if (print)
			ft_printf("pa\n");
	}
}

void	pb(t_pushswap *param, bool print)
{
	if (param->a->size)
	{
		if (!push(param->b, pop(param->a)))
			return (flush_pushswap(param, true));
		if (print)
			ft_printf("pb\n");
	}
}
