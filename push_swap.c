/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:07:26 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/21 01:29:02 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps/push_swap.h"

int	*ft_init_tab(char **args, int size)
{
	int	*int_tab;
	int	i;
	int	j;

	if (ft_check_args(size, args, 0) == 1)
	{
		ft_free_split(args);
		exit(1);
	}
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

char	**ft_combine_args(int argc, char **argv, int i)
{
	char	**args;
	char	**split;
	int		j;
	int		k;

	args = malloc(ft_argsize(argc, argv) * sizeof(char *));
	if (!args)
		return (NULL);
	k = 0;
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

void	ft_init_sort_free(int *tab, int size)
{
	t_stack	*stack_a;

	stack_a = NULL;
	ft_init_stack(&stack_a, tab, size);
	if (!ft_stack_is_sorted(&stack_a))
		ft_sort_stack(&stack_a, size);
	ft_free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	int		*tab;
	char	**args;
	int		size;

	tab = NULL;
	args = NULL;
	size = 0;
	if (ft_check_args(argc - 1, argv + 1, 0) == 0)
	{
		if (argc > 1)
		{
			args = ft_combine_args(argc, argv, 1);
			size = ft_count_args(args);
			tab = ft_init_tab(args, size);
			ft_free_split(args);
		}
	}
	if (size >= 2)
		ft_init_sort_free(tab, size);
	if (tab)
		free(tab);
	return (0);
}
