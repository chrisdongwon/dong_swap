/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:19 by cwon              #+#    #+#             */
/*   Updated: 2024/11/11 12:33:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "target.h"

void	push_swap(int argc, char **argv);

int		is_sorted(t_target *target);
int		*stack_to_array(t_target *target, int n);

void	sort(t_target *target);
void	sort_three(t_target *target);

#endif