/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:00:35 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/13 00:01:58 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_split(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void	ft_free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    free(stack);
    stack = NULL;
}

void	ft_free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
		ft_free_stack(*stack_a);
	if (*stack_b)
		ft_free_stack(*stack_b);
}
