/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:21:45 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/18 15:30:17 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Put the first element of the stack to the bottom
void	ft_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lastnode(*stack_a);
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = ft_lastnode(*stack_b);
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("rb\n");
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
	ft_printf("rr\n");
}
