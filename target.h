/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:12:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/10 16:41:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGET_H
# define TARGET_H

# include "stack.h"

typedef struct s_target
{
	t_stack	*a;
	t_stack	*b;
}	t_target;

int		init_target(t_target *target, t_stack *stack);
void	flush_target(t_target *target, int error);
void	print_target(t_target *target);

void	sa(t_target *target);
void	sb(t_target *target);
void	ss(t_target *target);
void	pa(t_target *target);
void	pb(t_target *target);
void	ra(t_target *target);
void	rb(t_target *target);
void	rr(t_target *target);
void	rra(t_target *target);
void	rrb(t_target *target);
void	rrr(t_target *target);

#endif