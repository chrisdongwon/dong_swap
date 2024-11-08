/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/08 15:50:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	t_list	*node;

	node = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = node;
	stack->bottom = node;
	node->next = 0;
}
