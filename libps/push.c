/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:16:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/12 23:21:07 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push the first element of the stack a to the top of the stack b
void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (*stack_a)
	{
		first = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a)
			(*stack_a)->prev = NULL;
		first->next = NULL;
		if (*stack_b == NULL)
			*stack_b = first;
		else
		{
			first->next = *stack_b;
			(*stack_b)->prev = first;
			*stack_b = first;
		}
		ft_printf("pa\n");
	}
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;

	if (*stack_b)
	{
		first = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_b)
			(*stack_b)->prev = NULL;
		first->next = NULL;
		if (*stack_a == NULL)
			*stack_a = first;
		else
		{
			first->next = *stack_a;
			(*stack_a)->prev = first;
			*stack_a = first;
		}
		ft_printf("pb\n");
	}
}
