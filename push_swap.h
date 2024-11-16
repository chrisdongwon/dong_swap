/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:19 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:42:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "target.h"

void	push_swap(int argc, char **argv);
void	sort(t_target *target);
void	print_sequence(t_target *target);

// data initialization
int		is_duplicate(t_stack *stack, int n);
t_stack	*set_data(int argc, char **argv);

// sorting helper functions
int		is_sorted(t_stack *stack, size_t size);
void	partition_a(t_target *target, size_t size);
void	partition_b(t_target *target, size_t size);


#endif