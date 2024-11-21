/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:08:08 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 15:20:31 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft/libft.h"
# include "list.h"

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// stack.c
t_stack	*init_stack(void);
void	flush_stack(t_stack *stack, int error);
void	print_stack(t_stack *stack);
int		push(t_stack *stack, int n);
int		pop(t_stack *stack);

#endif