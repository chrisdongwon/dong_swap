/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:08:55 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 15:12:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pushswap *param)
{
	if (param->b->size)
	{
		if (!push(param->a, pop(param->b)))
			return (flush_pushswap(param, true));
		ft_printf("pa\n");
	}
}

void	pb(t_pushswap *param)
{
	if (param->a->size)
	{
		if (!push(param->b, pop(param->a)))
			return (flush_pushswap(param, true));
		ft_printf("pb\n");
	}
}
