/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:46:00 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 14:57:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// doubly_linked_list.c
bool	insert(t_node **head, int data);
bool	remove(t_node **head);
t_node	*new_node(int data);
void	free_list(t_node **head);
bool	is_sorted(t_node *head);

#endif