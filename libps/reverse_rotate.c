/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:24:38 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/18 23:34:59 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Put the last element of the stack to the top.
void	ft_reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*last_prev;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = ft_lastnode(*stack_a);
	last_prev = last->prev;
	last_prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_a = last;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*last_prev;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = ft_lastnode(*stack_b);
	last_prev = last->prev;
	last_prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack_b = last;
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
