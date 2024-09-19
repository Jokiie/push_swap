
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:57:45 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/10 00:22:10 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [ ] to do : ft_sort_5
// [ ] to do : ft_sort_stack (until 500)
// [ ] to do : Checks the functions to check is the stack is empty
// [ ] to do : redo ft_sort 3 and 4 -> dont work with checker

void	ft_sort_2(t_stack **stack)
{
	if (((*stack)->content) > ((*stack)->next->content))
		ft_swap_a(stack);
	else
		return ;
}

void	ft_sort_3(t_stack **stack_a)
{
	t_stack	*last;

	last = ft_lastnode(*stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > last->content)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->next->content > (*stack_a)->content
		&& (*stack_a)->next->content > last->content)
		ft_reverse_rotate_a(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap_a(stack_a);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;
	int	min;

	min = ft_find_min(stack_a);
	while (!ft_stack_is_sorted(stack_a))
	{
		last = ft_lastnode(*stack_a);

	}
}

void	ft_sort_stack(t_stack **stack_a, int size)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (size == 0 || size == 1)
		return ;
	else if (size == 2)
		ft_sort_2(stack_a);
	else if (size == 3)
		ft_sort_3(stack_a);
	else if (size == 4 || size == 5)
		ft_sort_5(stack_a, &stack_b);
	else
		ft_radix_sort(stack_a, &stack_b, size);
}
