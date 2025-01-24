/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:41:43 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:35:34 by cwon             ###   ########.fr       */
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

// adjust.c
void	adjust(t_pushswap *param, int *a, int *b);
void	final_adjustment(t_pushswap *param);

// init.c
void	init_pushswap(t_pushswap *param, int argc, char **argv);

// minimum_rotation.c
void	get_minimum_rotation(t_pushswap *param, int *a, int *b);
int		top_location(t_pushswap *param);

// push_swap.c
void	flush_pushswap(t_pushswap *param, bool error);
void	push_swap(int argc, char **argv);

// quicksort.c
void	sort_array(t_pushswap *param);

// push.c
void	pa(t_pushswap *param, bool print);
void	pb(t_pushswap *param, bool print);

// reverse_rotate.c
void	rra(t_pushswap *param, bool print);
void	rrb(t_pushswap *param, bool print);
void	rrr(t_pushswap *param, bool print);

// rotate.c
void	ra(t_pushswap *param, bool print);
void	rb(t_pushswap *param, bool print);
void	rr(t_pushswap *param, bool print);

// swap.c
void	sa(t_pushswap *param, bool print);
void	sb(t_pushswap *param, bool print);
void	ss(t_pushswap *param, bool print);

#endif