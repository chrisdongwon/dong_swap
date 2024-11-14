/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:19 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 00:05:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "target.h"

void	push_swap(int argc, char **argv);

int		is_sorted(t_target *target, char choice, size_t size);

void	sort(t_target *target);
void	partition_a(t_target *target, size_t size);
void	partition_b(t_target *target, size_t size);

#endif