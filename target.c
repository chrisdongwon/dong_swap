/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/09 14:31:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	init_target(t_target *target, t_stack *stack)
{
	target->a = stack;
	target->b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(target->b);
}

void	flush_target(t_target *target)
{
	ft_lstclear(&(target->a->top), free);
	ft_lstclear(&(target->b->top), free);
	free(target->a);
	free(target->b);
}

void	print_target(t_target target)
{
	ft_printf("[stack a]\n");
	print_stack(*(target.a));
	ft_printf("[stack b]\n");
	print_stack(*(target.b));
}
