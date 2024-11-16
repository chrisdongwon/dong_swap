/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 02:27:27 by cwon              #+#    #+#             */
/*   Updated: 2024/11/17 02:53:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

void	print_sequence(t_target *target)
{
	t_list	*node;
	char	*data;
	size_t	i;

	node = target->sequence->bottom;
	i = 0;
	while (node && i < target->sequence->size)
	{
		data = node->content;
		ft_printf("%s\n", data);
		node = node->prev;
		i++;
	}
	flush_target(target, 0);
}

void	push_operation(t_target *target, char *operation)
{
	char	*data;
	t_list	*node;

	data = ft_strdup(operation);
	if (!data)
		return (flush_target(target, 1));
	node = ft_lstnew(data);
	if (!node)
		return (flush_target(target, 1));
	ft_lstadd_front(&target->sequence->top, node);
	target->sequence->size++;
	if (target->sequence->size == 1)
		target->sequence->bottom = target->sequence->top;
}
