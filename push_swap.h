/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:19 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 18:45:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "target.h"

// push_swap.c
int		is_sorted(t_stack *stack);
void	push_swap(int argc, char **argv);

// sort.c
void	sort(t_target *target);

// manual_sort.c
void	manual_sort(t_target *target);

#endif