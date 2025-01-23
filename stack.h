/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:32:29 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 15:46:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "doubly_linked_list.h"

typedef struct s_stack
{
	size_t	size;
	t_node	*bottom;
	t_node	*top;
}	t_stack;

// stack.c
bool	push(t_stack *stack, int data);
int		pop(t_stack *stack);
t_stack	*new_stack(void);
void	free_stack(t_stack *stack);
int		stack_extremum(t_stack *stack, int (*comparator)(int, int));

#endif