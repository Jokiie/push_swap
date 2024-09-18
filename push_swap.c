/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:07:26 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/18 01:30:32 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps/push_swap.h"

// [ ] to do : Separate the creation of the stack for 1 arg and 2 args
// [x] to do : Add a function to check if the stack is sorted
// [ ] to do : Add a structure that add a pointer to the first and last node

int	*ft_init_tab(char **args, int size)
{
	int	*int_tab;
	int	i;
	int	j;

	int_tab = (int *)malloc(sizeof(int) * size);
	if (!int_tab)
		return (NULL);
	i = 0;
	j = 0;
	while (args[i])
		int_tab[j++] = ft_atoi(args[i++]);
	return (int_tab);
}

void	ft_init_stack(t_stack **stack, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_addnode_back(stack, ft_newnode(&tab[i]));
		i++;
	}
}

void	ft_init_sort_free(t_stack **stack_a, int *tab, int size)
{
		ft_init_stack(stack_a, tab, size);
		if (!ft_stack_is_sorted(stack_a))		
			ft_sort_stack(stack_a, size);
		if (*stack_a)
		 	ft_printf_stack_content(*stack_a);
		ft_free_stack(*stack_a);
		if (tab)
			free(tab);
}

char	**ft_combine_args(int argc, char **argv)
{
	char	**args;
	char	**split;
	int		i;
	int		j;
	int		k;

	args = malloc(sizeof(char *) * (argc * 10));
	if (!args)
		return (NULL);
	k = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
			args[k++] = ft_strdup(split[j++]);
		ft_free_split(split);
		i++;
	}
	args[k] = NULL;
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*tab;
	char	**args;
	int		size;

	tab = NULL;
	stack_a = NULL;
	if (argc > 1)
	{
		args = ft_combine_args(argc, argv);
		size = ft_count_args(args);
		if (ft_check_args(size, args, 0) == 0)
			tab = ft_init_tab(args, size);
		else
		{
			ft_free_split(args);
			return (1);
		}
		ft_free_split(args);
	}
	if (size >= 2)
		ft_init_sort_free(&stack_a, tab, size);
	return (0);
}
