/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:33:08 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/07/07 18:12:36 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define ONLY_MINUS "-"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct stacks
{
	int				*array;
	int				pos_top;
	unsigned int	size;	
}	t_stack;

// push_swap.c
t_stack	*create_array(int size, char **av);
t_stack	*init(t_stack *a);

//check_array.c
int	check_duplicates(int size, char **av);
int	*create_keep_int(int size, char **av);

//helpers.c
int	ft_atoi(char *str);
//static int	ft_check_white_spaces(char *s);
int	ft_get_index(int *str1, int *str2);

//sort_action.c
void	push_a(char *name_ac, t_stack *a, t_stack *b);
void	push_b(char *name_ac, t_stack *a, t_stack *b);
void	rotate_one_stack(char *name_ac, t_stack *stack, int how_much);
void	swap_one_stack(char *name_ac, t_stack *stack, int how_much);
void	swap(int *first, int *second);

//sort_actions2.c

void	rrr(char *name_ac, t_stack *a, t_stack *b);
void	rr(char *name_ac, t_stack *a, t_stack *b);
void	ss(char *name_ac, t_stack *a, t_stack *b);
void	rr_one_stack(char *name_ac, t_stack *stack, int how_much);

//sort_small.c

void	lets_sort(int *copy_arr, t_stack *a, t_stack *b);
void	second_step(t_stack *a, t_stack *b);
void	first_step(t_stack *a, t_stack *b);
void	when_size_3(t_stack *a);

// sort_big.c

void	sort_with_radix(t_stack *dup, t_stack *b);
int	get_max_bits(int max_number);

// sort_helpers.c

int	compare_stack(int *array, t_stack *stack);
int	ft_memcmp(void *str1, void *str2, size_t n);

//sorting.process.c

t_stack *convert_list(t_stack *a);
int	*copy_stack(t_stack *stack);
void	sort_array(int *tab, int size);

// max_min.c

int	mid_sorted(int *array, int size);
int	min(t_stack *stack);
int	max(t_stack *stack);

// error file.c

void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);

#endif