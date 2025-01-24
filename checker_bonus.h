/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:51:12 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:38:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "operations_bonus.h"

typedef struct s_checker
{
	t_ops		*ops;
	t_pushswap	*param;
}	t_checker;

typedef void	(*t_operation)(t_pushswap *, bool);

// checker_bonus.h
t_operation	get_operation(t_checker *checker, char *str);
void		apply_operations(t_checker *checker);
void		flush_checker(t_checker *checker, bool error);
void		init_checker(t_checker *checker, int argc, char **argv);

#endif