/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:46:35 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 14:56:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

bool	insert(t_node **head, int data)
{
	t_node	*node;

	node = new_node(data);
	if (!node)
		return (false);
	node->next = *head;
	if (*head)
		(*head)->prev = node;
	*head = node;
	return (true);
}

bool	remove(t_node **head)
{
	t_node	*node;

	if (!(*head))
		return (false);
	node = *head;
	*head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
	return (true);
}

t_node	*new_node(int data)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	if (!result)
		return (0);
	result->data = data;
	result->next = 0;
	result->prev = 0;
	return (result);
}

void	free_list(t_node **head)
{
	while (*head)
		remove(head);
	free(*head);
	*head = 0;
}

bool	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (false);
		head = head->next;
	}
	return (true);
}
