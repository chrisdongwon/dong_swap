/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:02:22 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 13:39:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

bool	append_operation(t_ops *ops, char *str)
{
	t_list	*node;

	node = ft_lstnew(str);
	if (!node)
		return (false);
	ft_lstadd_front(&(ops->top), node);
	ops->size++;
	if (ops->size == 1)
		ops->bottom = ops->top;
	return (true);
}

t_ops	*new_operations(void)
{
	t_ops	*result;

	result = (t_ops *)malloc(sizeof(t_ops));
	if (!result)
		return (0);
	result->top = 0;
	result->bottom = 0;
	result->size = 0;
	return (result);
}

void	free_operations(t_ops *ops)
{
	ft_lstclear(&(ops->top), free);
	free(ops);
}
