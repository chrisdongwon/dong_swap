/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:08:08 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:08:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	size_t	size;
}	t_stack;

t_stack	*init_stack(void);
void	flush_stack(t_stack *stack, int error);
void	print_stack(t_stack *stack);

void	push(t_stack *stack, int n);
int		*pop(t_stack *stack);

#endif