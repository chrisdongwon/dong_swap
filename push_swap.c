/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:53:07 by cwon              #+#    #+#             */
/*   Updated: 2024/11/24 17:15:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_target	*target;

	target = init_target(argc, argv);
	if (!is_sorted(target->a))
		sort(target);
	if (!is_sorted(target->a))
		flush_target(target, 1);
	flush_target(target, 0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
