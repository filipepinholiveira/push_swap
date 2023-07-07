/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:32:05 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 17:35:21 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	when_size_3(t_stack *a)
{
	if (a->array[a->pos_top] < a->array[a->pos_top + 1]
		&& a->array[a->pos_top] < a->array[a->pos_top + 2]
		&& a->array[a->pos_top + 1] == max(a))
	{
		swap_one_stack(SA, a, 1);
		rotate_one_stack(RA, a, 1);
	}
	else if (a->array[a->pos_top + 2] == max(a)
		&& a->array[a->pos_top + 1] == min(a))
		swap_one_stack(SA, a, 1);
	else if (a->array[a->pos_top] == max(a)
		&& a->array[a->pos_top + 2] == min(a))
	{
		swap_one_stack(SA, a, 1);
		rr_one_stack(RRA, a, 1);
	}
	else if (a->array[a->pos_top] == max(a)
		&& a->array[a->pos_top + 1] == min(a))
		rotate_one_stack(RA, a, 1);
	else if (a->array[a->pos_top + 1] == max(a)
		&& a->array[a->pos_top + 2] == min(a))
		rr_one_stack(RRA, a, 1);
}

void	first_step(t_stack *a, t_stack *b)
{
	while (b->size != 2)
	{
		if (a->array[a->pos_top] == 0 || a->array[a->pos_top] == 1)
			push_b(PB, a, b);
		else
			rotate_one_stack(RA, a, 1);
	}
	when_size_3(a);
}

void	second_step(t_stack *a, t_stack *b)
{
	if (b->array[b->pos_top] < b->array[b->pos_top + 1])
		swap_one_stack(SB, b, 1);
	push_a(PA, a, b);
	push_a(PA, a, b);
}

void	lets_sort(int *copy_arr, t_stack *a, t_stack *b)
{
	if (a->size == 3)
		when_size_3(a);
	else if (compare_stack(copy_arr, a))
	{
		first_step(a, b);
		second_step(a, b);
	}
}