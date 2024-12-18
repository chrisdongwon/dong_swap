/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:52:33 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 11:08:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	pa(t_target *target, int print)
{
	if (target->b->size)
	{
		if (!push(target->a, pop(target->b)))
			return (flush_target(target, 1));
		if (print)
			ft_printf("pa\n");
	}
}

void	pb(t_target *target, int print)
{
	if (target->a->size)
	{
		if (!push(target->b, pop(target->a)))
			return (flush_target(target, 1));
		if (print)
			ft_printf("pb\n");
	}
}
