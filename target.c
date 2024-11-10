/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/10 16:41:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

int	init_target(t_target *target, t_stack *stack)
{
	target->a = stack;
	target->b = (t_stack *)malloc(sizeof(t_stack));
	if (!target->b)
		return (0);
	init_stack(target->b);
	return (1);
}

void	flush_target(t_target *target, int error)
{
	if (error)
		ft_printf("Error\n");
	if (target)
	{
		flush_stack(target->a, 0);
		flush_stack(target->b, 0);
	}
	free(target);
}

void	print_target(t_target *target)
{
	ft_printf("[stack a]\n");
	print_stack(target->a);
	ft_printf("[stack b]\n");
	print_stack(target->b);
}
