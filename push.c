/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:52:33 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:44:34 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	pa(t_target *target)
{
	int	*data;

	data = pop(target->b);
	if (data)
	{
		push(target->a, *data);
		push_operation(target, "pa");
		free(data);
	}
}

void	pb(t_target *target)
{
	int	*data;

	data = pop(target->a);
	if (data)
	{
		push(target->b, *data);
		push_operation(target, "pb");
		free(data);
	}
}
