/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:42:25 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 10:09:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_STACK_BONUS_H
# define OPERATION_STACK_BONUS_H

# include "libft/libft.h"

typedef struct s_op_stack
{
	t_list	*top;
	t_list	*bottom;
	size_t	size;
}	t_op_stack;

// operation_stack_bonus.c
t_op_stack	*init_operation_stack(void);
void		flush_operation_stack(t_op_stack *stack, int error);
int			push_operation(t_op_stack *stack, char *str);

#endif