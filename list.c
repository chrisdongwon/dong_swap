/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:46:44 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 14:49:34 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->content = 0;
		node->prev = 0;
		node->next = 0;
	}
	return (node);
}

void	add_node(t_node **list, t_node *node)
{
	if (node && list)
	{
		if (*list)
			(*list)->prev = node;
		node->next = *list;
		*list = node;
	}
}

void	flush_list(t_node **list)
{
	if (list && *list)
	{
		if ((*list)->next)
			flush_list(&((*list)->next));
		free(*list);
		*list = 0;
	}
}
