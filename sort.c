/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:22:08 by cwon              #+#    #+#             */
/*   Updated: 2024/11/14 13:56:22 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_target *target)
{
	partition_a(target, target->a->size);
}

void	partition_a(t_target *target, size_t size)
{
	int		*arr;
	int		*data;
	int		n;
	size_t	i;
	size_t	pb_count;
	size_t	ra_count;
	size_t	rb_count;
		
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if(!is_sorted(target, 'a', 2))
			sa(target);
		return ;
	}
	
	arr = stack_to_array(target, 'a', size);
	if (!arr)
		return (flush_target(target, 1));
	array_sort(arr, size);
	
	pb_count = 0;
	ra_count = 0;
	rb_count = 0;
	i = 0;
	
	while (i < size)
	{
		data = target->a->top->content;
		n = *data;
		if (n >= arr[size * 2 / 3])
		{
			ra(target);
			ra_count++;
		}
		else
		{
			pb(target);
			pb_count++;
			
			if (n >= arr[size / 3])
			{				
				rb(target);
				rb_count++;
			}
		}
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		rra(target);
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		rrb(target);
		i++;
	}
	
	free(arr);
	
	partition_a(target, ra_count);
	partition_b(target, pb_count);
	//partition_b(target, pb_count - rb_count);
}

void	partition_b(t_target *target, size_t size)
{
	int		*arr;
	int		*data;
	int		n;
	size_t	i;
	size_t	pa_count;
	size_t	ra_count;
	size_t	rb_count;

	if (size <= 1)
		return (pa(target));
	else if (size == 2)
	{
		if (is_sorted(target,'b', 2))
			sb(target);
		pa(target);
		pa(target);
		return ;
	}
	
	arr = stack_to_array(target, 'b', size);
	if (!arr)
		return (flush_target(target, 1));
	array_sort(arr, size);
	
	pa_count = 0;
	ra_count = 0;
	rb_count = 0;
	i = 0;
	while (i < size)
	{
		data = target->b->top->content;
		n = *data;
		if (n < arr[size / 3])
		{
			rb(target);
			rb_count++;
		}
		else
		{
			pa(target);
			pa_count++;
			if (n < arr[size * 2 / 3])
			{
				ra(target); 
				ra_count++;
			}
		}
		i++;
	}
	free(arr);
	partition_a(target, pa_count - ra_count);
		i = 0;
	while (i < ra_count)
	{
		rra(target);
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		rrb(target);
		i++;
	}
	partition_a(target, ra_count);
	partition_b(target, rb_count);
}
