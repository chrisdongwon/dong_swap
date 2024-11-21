/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:40:32 by cwon              #+#    #+#             */
/*   Updated: 2024/11/21 18:04:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int* a, int* b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int partition(int *arr, int low, int high)
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

void quick_sort(int *arr, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(arr, low, high);
		quick_sort(arr, low, i - 1);
		quick_sort(arr, i + 1, high);
	}
}

void sort_array(int *array, int size)
{
	quick_sort(array, 0, size - 1);
}
