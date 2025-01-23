/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:43 by cwon              #+#    #+#             */
/*   Updated: 2025/01/23 10:14:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low;
	j = low - 1;
	while (++j < high)
	{
		if (arr[j] < pivot)
			swap(&arr[i++], &arr[j]);
	}
	swap(&arr[i], &arr[high]);
	return (i);
}

static void	quicksort(int *arr, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(arr, low, high);
		quicksort(arr, low, i - 1);
		quicksort(arr, i + 1, high);
	}
}

static void	check_duplicates(t_pushswap *param)
{
	size_t	i;

	i = 0;
	while (i < param->array_size - 1)
	{
		if (param->array[i] == param->array[i + 1])
			flush_pushswap(param, true);
		i++;
	}
}

void	sort_array(t_pushswap *param)
{
	quicksort(param->array, 0, param->array_size - 1);
	check_duplicates(param);
}
