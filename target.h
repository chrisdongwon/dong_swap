/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:12:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 17:55:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGET_H
# define TARGET_H

# include "stack.h"

typedef struct s_target
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
}	t_target;

// target.c
t_target	*init_target(t_stack *stack);
void		flush_target(t_target *target, int error);
void		print_target(t_target *target);

// target_util.c
void		sort_array(int *array, int size);

// swap.c
void		sa(t_target *target);
void		sb(t_target *target);
void		ss(t_target *target);

// push.c
void		pa(t_target *target);
void		pb(t_target *target);

// rotate.c
void		ra(t_target *target);
void		rb(t_target *target);
void		rr(t_target *target);

// reverse.c
void		rra(t_target *target);
void		rrb(t_target *target);
void		rrr(t_target *target);

#endif