/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:52:33 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 13:03:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	pa(t_target *target)
{
	int	*data;

	data = pop(target->b);
	if (data)
	{
		ft_printf("pa\n");
		push(target->a, *data);
		free(data);
	}
}

void	pb(t_target *target)
{
	int	*data;

	data = pop(target->a);
	if (data)
	{
		ft_printf("pb\n");
		push(target->b, *data);
		free(data);
	}
}
