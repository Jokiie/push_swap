/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:16:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/20 00:57:44 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If b is not empty it takes the first element on top of b and puts it on a.
void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (!stack_b || !*stack_b)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first->next = NULL;
	first->prev = NULL;
	if (!stack_a || !*stack_a)
		*stack_a = first;
	else
	{
		first->next = *stack_a;
		(*stack_a)->prev = first;
		*stack_a = first;
	}
	ft_printf("pa\n");
}

// If a is not empty, it takes the first element on top of a and puts it on b.
void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (!stack_a || !*stack_a)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first->next = NULL;
	first->prev = NULL;
	if (!stack_b || !*stack_b)
		*stack_b = first;
	else
	{
		first->next = *stack_b;
		(*stack_b)->prev = first;
		*stack_b = first;
	}
	ft_printf("pb\n");
}
