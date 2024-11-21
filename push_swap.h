/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:19 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 21:58:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "target.h"

// push_swap.c
int		is_sorted(t_stack *stack);
void	push_swap(int argc, char **argv);

// manual_sort.c
void	manual_sort(t_target *target);

// sort.c
void	sort(t_target *target);

// minimum_rotation.c
void	minimum_rotation(t_target *target);

// best_location.c
int		best_location(t_target *target, int data);
int		top_bottom_location(t_target *target, int index, int is_top);

#endif