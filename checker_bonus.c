/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:35:09 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 11:10:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	apply_operations(t_checker *checker)
{
	t_list				*node;
	t_target_operation	operation;

	node = checker->operations->bottom;
	while (node)
	{
		operation = get_operation(checker, (char *)node->content);
		operation(checker->target, 0);
		node = node->prev;
	}
}

static t_checker	*init_checker(int argc, char **argv)
{
	t_target	*stacks_ab;
	t_checker	*checker;

	stacks_ab = init_target(argc, argv);
	checker = (t_checker *)malloc(sizeof(t_checker));
	if (!checker)
		flush_target(stacks_ab, 1);
	checker->target = stacks_ab;
	set_operations(checker);
	return (checker);
}

static void	checker(int argc, char **argv)
{
	t_checker	*checker;

	checker = init_checker(argc, argv);
	apply_operations(checker);
	if (is_sorted(checker->target->a) && !checker->target->b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	flush_checker(checker, 0);
}

void	flush_checker(t_checker *checker, int error)
{
	if (checker)
	{
		if (checker->target)
			flush_target(checker->target, 0);
		if (checker->operations)
			flush_operation_stack(checker->operations, 0);
		free(checker);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		checker(argc, argv);
	return (0);
}
