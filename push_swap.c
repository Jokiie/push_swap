/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:07:26 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 17:48:19 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps/push_swap.h"

// [ ] to do : Separate the creation of the stack for 1 arg and 2 args
// [ ] to do : Add a function to check if the stack is sorted
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
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tab;
	char	**args;
	int		size;

	tab = NULL;
	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		size = ft_count_args(args);
		if (ft_check_args(size, args, 0) == 0)
		{
			tab = ft_init_tab(args, size);
			ft_init_stack(&stack_a, tab, size);
		}
		ft_free_split(args);
	}
	else if (argc > 2)
	{
		size = argc - 1;
		if (ft_check_args(argc, argv, 1) == 0)
		{
			tab = ft_init_tab(argv + 1, size);
			ft_init_stack(&stack_a, tab, size);
		}
	}
	ft_sort_stack(&stack_a, &stack_b, size);
	if (stack_a)
		ft_printf_stack_content(stack_a);
	ft_free_stacks(&stack_a, &stack_b);
	if (tab)
		free(tab);
	return (0);
}
