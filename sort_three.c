/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:15:13 by cwon              #+#    #+#             */
/*   Updated: 2024/11/11 12:32:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_target *target)
{
	int	*arr;

	arr = stack_to_array(target, 3);
	if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[0] < arr[2]))
	{
		rra(target);
		sa(target);
	}
	else if ((arr[0] < arr[1]) && (arr[1] > arr[2]) && (arr[0] > arr[2]))
		rra(target);
	else if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[0] < arr[2]))
		sa(target);
	else if ((arr[0] > arr[1]) && (arr[1] < arr[2]) && (arr[0] > arr[2]))
		ra(target);
	else
	{
		sa(target);
		rra(target);
	}
	free(arr);
}
