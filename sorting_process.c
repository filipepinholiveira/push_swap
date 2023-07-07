/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:18:34 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 16:38:42 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	sort_array(int *tab, int size)
{
	int	x;
	int	y;
	int	swap;

	x = 1;
	while (x < size)
	{
		swap = tab[x];
		y = x - 1;
		while (y >= 0 && tab[y] > swap)
		{
			tab[y + 1] = tab[y];
			y = y - 1;
		}
		tab[y + 1] = swap;
		x++;
	}
}

int	*copy_stack(t_stack *stack)
{
	int				*c;
	unsigned int	i;

	i = 0;
	c = malloc (stack->size * sizeof(int));
	while (i != stack->size)
	{
		c[i] = stack->array[i];
		i++;
	}
	return(c);
}

t_stack *convert_list(t_stack *a)
{
	t_stack			*convert_list;
	int				*organized_array;
	unsigned int	i;

	convert_list = init(a);
	organized_array = copy_stack(a);
	sort_array(organized_array, a->size);
	i = 0;
	while (i != a->size)
	{
		convert_list->array[i] = ft_get_index(&a->array[i], organized_array);
		i++;
	}
	convert_list->size = a->size;
	convert_list->pos_top = 0;
	free(organized_array);
	return(convert_list);
}