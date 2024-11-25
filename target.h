/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:12:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 10:17:58 by cwon             ###   ########.fr       */
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
t_target	*init_target(int argc, char **argv);
void		flush_target(t_target *target, int error);

// target_util.c
void		sort_array(int *array, int size);

// swap.c
void		sa(t_target *target, int print);
void		sb(t_target *target, int print);
void		ss(t_target *target, int print);

// push.c
void		pa(t_target *target, int print);
void		pb(t_target *target, int print);

// rotate.c
void		ra(t_target *target, int print);
void		rb(t_target *target, int print);
void		rr(t_target *target, int print);

// reverse.c
void		rra(t_target *target, int print);
void		rrb(t_target *target, int print);
void		rrr(t_target *target, int print);

#endif