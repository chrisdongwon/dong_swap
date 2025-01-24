/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:52:21 by cwon              #+#    #+#             */
/*   Updated: 2025/01/24 15:38:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_operation	get_operation(t_checker *checker, char *str)
{
	if (!ft_strncmp(str, "sa\n", 4))
		return (sa);
	if (!ft_strncmp(str, "sb\n", 4))
		return (sb);
	if (!ft_strncmp(str, "ss\n", 4))
		return (ss);
	if (!ft_strncmp(str, "ra\n", 4))
		return (ra);
	if (!ft_strncmp(str, "rb\n", 4))
		return (rb);
	if (!ft_strncmp(str, "rr\n", 4))
		return (rr);
	if (!ft_strncmp(str, "rra\n", 5))
		return (rra);
	if (!ft_strncmp(str, "rrb\n", 5))
		return (rrb);
	if (!ft_strncmp(str, "rrr\n", 5))
		return (rrr);
	if (!ft_strncmp(str, "pa\n", 4))
		return (pa);
	if (!ft_strncmp(str, "pb\n", 4))
		return (pb);
	flush_checker(checker, true);
	return (0);
}

void	apply_operations(t_checker *checker)
{
	t_list		*node;
	t_operation	operation;

	node = checker->ops->bottom;
	while (node)
	{
		operation = get_operation(checker, node->content);
		operation(checker->param, false);
		node = node->prev;
	}
}

void	flush_checker(t_checker *checker, bool error)
{
	if (checker->ops)
		free_operations(checker->ops);
	if (checker->param)
	{
		flush_pushswap(checker->param, false);
		free(checker->param);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	init_checker(t_checker *checker, int argc, char **argv)
{
	char	*line;
	int		status;

	checker->ops = 0;
	checker->param = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!checker->param)
		flush_checker(checker, true);
	init_pushswap(checker->param, argc, argv);
	checker->ops = new_operations();
	if (!checker->ops)
		flush_checker(checker, true);
	status = get_next_line(STDIN_FILENO, &line);
	while (status && line)
	{
		append_operation(checker->ops, line);
		status = get_next_line(STDIN_FILENO, &line);
	}
	if (!status)
		flush_checker(checker, true);
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	if (argc > 1)
	{
		init_checker(&checker, argc, argv);
		apply_operations(&checker);
		if (is_sorted(checker.param->a->top) && !checker.param->b->size)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		flush_checker(&checker, false);
	}
	return (0);
}
