/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:21:45 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/12 23:20:51 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Put the first element of the stack to the bottom
void	ft_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		second = first->next;
		last = ft_lastnode(*stack_a);
		first->next = NULL;
		second->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack_a = second;
		ft_printf("ra\n");
	}
}

void	ft_rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = first->next;
		last = ft_lastnode(*stack_b);
		first->next = NULL;
		second->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack_b = second;
		ft_printf("rb\n");
	}
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
	ft_printf("rr\n");
}
