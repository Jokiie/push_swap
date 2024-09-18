/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:19:30 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 19:35:49 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first 2 elements at the top of the stack
void	ft_swap_a(t_stack **stack_a)
{
	t_stack	*first;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	first->next = (*stack_a)->next;
	(*stack_a)->next = first;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	t_stack	*first;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	first->next = (*stack_b)->next;
	(*stack_b)->next = first;
	ft_printf("sb\n");
}

void	ft_swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	ft_printf("ss\n");
}
