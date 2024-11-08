/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:34 by cwon              #+#    #+#             */
/*   Updated: 2024/11/08 15:34:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	*first;
	int	*second;

	if (stack->size >= 2)
	{
		first = pop(stack);
		second = pop(stack);
		push(stack, *first);
		push(stack, *second);
		free(first);
		free(second);
	}
}
