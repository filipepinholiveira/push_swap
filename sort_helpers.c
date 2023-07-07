/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:13:33 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 18:16:27 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_memcmp(void *str1, void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned int *)str1)[i] != ((unsigned int *)str2)[i])
			return (((int *)str1)[i] - ((int *)str2)[i]);
		i++;
	}
	return (0);
}

int	compare_stack(int *array, t_stack *stack)
{
	int	n;

	n = stack->size;
	if (ft_memcmp(stack->array, array, n))
		return (1);
	return (0);
}
