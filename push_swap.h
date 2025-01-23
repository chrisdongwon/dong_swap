/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:41:43 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 18:52:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack.h"

typedef struct s_pushswap
{
	int		*array;
	size_t	array_size;
	t_stack	*a;
	t_stack	*b;
}	t_pushswap;

// init.c
void	init_pushswap(t_pushswap *param, int argc, char **argv);

// push_swap_util.c
void	flush_pushswap(t_pushswap *param, bool error);
void	tripartition(t_pushswap *param);
void	print_pushswap(t_pushswap *param);

// minimum_rotation.c
void	get_minimum_rotation(t_pushswap *param, int *a, int *b);
int		top_location(t_pushswap *param);

// adjust.c
void	adjust(t_pushswap *param, int *a, int *b);
void	final_adjustment(t_pushswap *param);

// quicksort.c
void	sort_array(t_pushswap *param);

// push.c
void	pa(t_pushswap *param);
void	pb(t_pushswap *param);

// reverse_rotate.c
void	rra(t_pushswap *param);
void	rrb(t_pushswap *param);
void	rrr(t_pushswap *param);

// rotate.c
void	ra(t_pushswap *param);
void	rb(t_pushswap *param);
void	rr(t_pushswap *param);

// swap.c
void	sa(t_pushswap *param);
void	sb(t_pushswap *param);
void	ss(t_pushswap *param);

#endif