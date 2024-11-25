/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:35:37 by cwon              #+#    #+#             */
/*   Updated: 2024/11/25 10:08:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	extract_operation(t_checker *checker, char *operation)
{
	char	buffer;
	ssize_t	bytes_read;
	size_t	i;

	buffer = 0;
	bytes_read = -1;
	i = 0;
	while (buffer != '\n' && bytes_read)
	{
		bytes_read = read(0, &buffer, 1);
		if (bytes_read == -1)
			return (flush_checker(checker, 1));
		if (bytes_read)
			operation[i++] = buffer;
		if (i > 4)
			return (flush_checker(checker, 1));
	}
	if ((!i && operation[i] == '\n') || (i && operation[i - 1] != '\n'))
		return (flush_checker(checker, 1));
	if (!bytes_read)
		operation[0] = 0;
	else
		operation[i - 1] = 0;
}

void	set_operations(t_checker *checker)
{
	char	operation[5];
	char	*str;
	ssize_t	length;

	checker->operations = init_operation_stack();
	length = -1;
	while (length)
	{
		extract_operation(checker, operation);
		length = ft_strlen(operation);
		if (length)
		{
			str = ft_strdup(operation);
			if (!str)
				return (flush_checker(checker, 1));
			if (!push_operation(checker->operations, str))
				return (flush_checker(checker, 1));
		}
	}
}

t_target_operation	get_operation(t_checker *checker, char *str)
{
	if (!ft_strncmp(str, "sa", ft_strlen(str)))
		return (sa);
	if (!ft_strncmp(str, "sb", ft_strlen(str)))
		return (sb);
	if (!ft_strncmp(str, "ss", ft_strlen(str)))
		return (ss);
	if (!ft_strncmp(str, "ra", ft_strlen(str)))
		return (ra);
	if (!ft_strncmp(str, "rb", ft_strlen(str)))
		return (rb);
	if (!ft_strncmp(str, "rr", ft_strlen(str)))
		return (rr);
	if (!ft_strncmp(str, "rra", ft_strlen(str)))
		return (rra);
	if (!ft_strncmp(str, "rrb", ft_strlen(str)))
		return (rrb);
	if (!ft_strncmp(str, "rrr", ft_strlen(str)))
		return (rrr);
	if (!ft_strncmp(str, "pa", ft_strlen(str)))
		return (pa);
	if (!ft_strncmp(str, "pb", ft_strlen(str)))
		return (pb);
	flush_checker(checker, 1);
	return (0);
}
