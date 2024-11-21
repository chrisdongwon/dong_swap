/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:52:33 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 15:33:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	pa(t_target *target)
{
	if (target->b->size)
	{
		if (!push(target->a, pop(target->b)))
			return (flush_target(target, 1));
		ft_printf("pa\n");
	}
}

void	pb(t_target *target)
{
	if (target->a->size)
	{
		if (!push(target->b, pop(target->a)))
			return (flush_target(target, 1));
		ft_printf("pb\n");
	}
}
