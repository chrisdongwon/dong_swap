/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:16 by cwon              #+#    #+#             */
/*   Updated: 2024/11/13 13:58:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

static int	*duplicate(int *arr, size_t size, size_t start)
{
	int		*result;
	size_t	i;

	result = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		result[i] = arr[start + i];
		i++;
	}
	return (result);
}

static void	merge(int arr[], size_t left, size_t middle, size_t right)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		*halves[2];

	halves[0] = duplicate(arr, middle - left + 1, left);
	halves[1] = duplicate(arr, right - middle, middle + 1);
	i = 0;
	j = 0;
	k = left;
	while ((i < middle - left + 1) && (j < right - middle))
	{
		if (halves[0][i] <= halves[1][j])
			arr[k++] = halves[0][i++];
		else
			arr[k++] = halves[1][j++];
	}
	while (i < middle - left + 1)
		arr[k++] = halves[0][i++];
	while (j < right - middle)
		arr[k++] = halves[1][j++];
	free(halves[0]);
	free(halves[1]);
}

static void	merge_sort(int *arr, size_t left, size_t right)
{
	size_t	middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

void	array_sort(int *arr, size_t size)
{
	merge_sort(arr, 0, size - 1);
}
