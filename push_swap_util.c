/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:22:26 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 18:43:41 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_pushswap(t_pushswap *param, bool error)
{
	if (param->array)
		free(param->array);
	if (param->a)
		free_stack(param->a);
	if (param->b)
		free_stack(param->b);
	if (error)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	tripartition(t_pushswap *param)
{
	int		low_pivot;
	int		high_pivot;
	size_t	count;

	low_pivot = param->array[param->a->size / 3];
	high_pivot = param->array[param->a->size * 2 / 3];
	count = param->a->size;
	while (count)
	{
		if (param->a->top->data < low_pivot)
		{
			pb(param);
			rb(param);
		}
		else if (param->a->top->data < high_pivot)
			pb(param);
		else
			ra(param);
		count--;
	}
}

void	print_pushswap(t_pushswap *param)
{
	t_node	*node;

	ft_printf("--------------------------------\n");
	ft_printf("Stack a:\n");
	node = param->a->top;
	while (node)
	{
		ft_printf("%d ", node->data);
		node = node->next;
	}
	ft_printf("\n");
	ft_printf("Size: %ld\n", param->a->size);
	ft_printf("Stack b:\n");
	node = param->b->top;
	while (node)
	{
		ft_printf("%d ", node->data);
		node = node->next;
	}
	ft_printf("\n");
	ft_printf("Size: %ld\n", param->b->size);
	ft_printf("--------------------------------\n");
}
