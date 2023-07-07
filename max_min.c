/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:02:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 18:06:27 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	unsigned int	i;
	int				max;

	i = stack->pos_top;
	max = stack->array[i];
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

int	min(t_stack *stack)
{
	unsigned int	i;
	int				min;

	min = stack->size;
	i = stack->pos_top;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	mid_sorted(int *array, int size)
{
	sort_array(array, size);
	return (array[size / 2]);
}