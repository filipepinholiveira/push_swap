/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:37:56 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 18:08:56 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(t_stack *a)
{
	t_stack *b;
	
	b = malloc (sizeof(*b));
	b->size = 0;
	b->pos_top = 0;
	b->array = calloc(a->size, sizeof(int));
	return (b);
}

t_stack	*create_array(int size, char **av)
{
	t_stack	*a;
	int		i;

	i = 0;
	if (!check_duplicates(size, av))
	{
		a = malloc (sizeof(*a));
		if (!a)
			return (NULL);
		a->array = malloc (size * sizeof(int));
		a->size = size;
		a->pos_top = 0;
		while (av[i + 1])
		{
			a->array[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	else
	{
		printf("erro\n");
		exit (0);
	}
	return (a);
}


int main(int ac, char **av)
{

t_stack *a;
t_stack *b;
t_stack *convert_positive;
int	*receive_array;

if (ac == 1)
	exit(0);
a = create_array((ac - 1), av);
b = init(a);
convert_positive = convert_list(a);
receive_array = copy_stack(convert_positive);
sort_array(receive_array, convert_positive->size);
if (a->size > 5 && compare_stack(receive_array, convert_positive))
	sort_with_radix(convert_positive, b);
else
	lets_sort(receive_array, convert_positive, b);
}
