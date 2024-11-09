/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:59:37 by cwon              #+#    #+#             */
/*   Updated: 2024/11/09 20:19:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

int	main(void)
{
	t_target	target;
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	init_stack(stack);
	for (int i = 0; i < 10; i++)
		push(stack, rand() % 100 + 1);

	init_target(&target, stack);
	print_target(target);
	
	pb(&target);
	//pb(&target);
	rr(&target);
	print_target(target);

	flush_target(&target);
	return (0);
}
