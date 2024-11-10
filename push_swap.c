/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:07 by cwon              #+#    #+#             */
/*   Updated: 2024/11/10 17:50:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	to do: duplicate check
int	get_stack(t_stack *stack, int argc, char **argv)
{
	size_t	i;

	init_stack(stack);
	i = argc;
	while (--i)
	{
		if (!ft_isinteger(argv[i]))
			return (0);
		push(stack, ft_atoi(argv[i]));
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	t_stack		*stack;
	t_target	*target;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack || !get_stack(stack, argc, argv))
		return (flush_stack(stack, 1));
	target = (t_target *)malloc(sizeof(t_target));
	if (!target || !init_target(target, stack))
		return (flush_target(target, 1));
	print_target(target);
	flush_target(target, 0);
}
