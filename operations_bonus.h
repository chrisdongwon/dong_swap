/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:00:19 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 12:56:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_BONUS_H
# define OPERATIONS_BONUS_H

# include "push_swap.h"

typedef struct s_ops
{
	size_t	size;
	t_list	*bottom;
	t_list	*top;
}	t_ops;

bool	append_operation(t_ops *ops, char *str);
t_ops	*new_operations(void);
void	free_operations(t_ops *ops);

#endif