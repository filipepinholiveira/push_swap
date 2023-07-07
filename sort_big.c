/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:11:25 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 18:13:09 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	get_max_bits(int max_number)
{
	int	max_bits;

	max_bits = 0;
	while ((max_number >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_with_radix(t_stack *dup, t_stack *b)
{
	unsigned int	max_number;
	unsigned int	max_bits;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	max_number = dup->size - 1;
	max_bits = get_max_bits(max_number);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < dup->size)
		{
			if (((dup->array[dup->pos_top] >> i) & 1) == 0)
				push_b(PB, dup, b);
			else
				rotate_one_stack(RA, dup, 1);
		}
		while (b->size != 0)
			push_a(PA, dup, b);
		if (b->size == 0)
			b->pos_top = 0;
	}
}