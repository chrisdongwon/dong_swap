/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:33:21 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 11:10:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "target.h"
# include "operation_stack_bonus.h"

typedef struct s_checker
{
	t_target	*target;
	t_op_stack	*operations;
}	t_checker;

typedef void	(*t_target_operation)(t_target *, int);

// checker_bonus.c
void				flush_checker(t_checker *checker, int error);

// checker_util_bonus.c
void				set_operations(t_checker *checker);
t_target_operation	get_operation(t_checker *checker, char *str);

#endif