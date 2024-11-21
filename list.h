/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:42:23 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 15:20:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include  <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// list.c
t_node	*new_node(void);
void	add_node(t_node **list, t_node *node);
void	flush_list(t_node **list);

#endif