/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:32:39 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/20 01:32:41 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_more(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min;

	while (*stack_a && size > 3 && !ft_stack_is_sorted(stack_a))
	{
		min = ft_find_min(stack_a);
		if ((*stack_a)->content == min)
		{
			ft_push_b(stack_a, stack_b);
			size--;
		}
		else if (ft_lastnode(*stack_a)->content == min)
		{
			ft_reverse_rotate_a(stack_a);
			ft_push_b(stack_a, stack_b);
			size--;
		}
		else
			ft_rotate_a(stack_a);
	}
	ft_sort_3(stack_a);
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
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
	else if (size > 3 && size <= 20)
		ft_sort_more(stack_a, &stack_b, size);
	else
		ft_radix_sort(stack_a, &stack_b, size);
}
