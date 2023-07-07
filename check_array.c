/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:31:37 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 16:07:43 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_keep_int(int size, char **av)
{
	int	i;
	int *keep_int;

	keep_int = malloc (size * sizeof(int));
	if (!keep_int)
		return (0);
	i = 0;
	while (av[i + 1])
	{
		keep_int[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return(keep_int);
}

int	check_duplicates(int size, char **av)
{
	int	i;
	int	j;
	int *keep_int;

	keep_int = create_keep_int(size, av);
	i = -1;
	j = 0;
	while (++i < size)
	{
		j = i;
		while(++j < size)
		{	
			if (keep_int[i] == keep_int[j])
			{
				free(keep_int);
				return (1);
			}
		}
	}
	free(keep_int);
	return (0);
}