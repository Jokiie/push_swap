/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:25:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 19:43:46 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_printf_stack_content(t_stack *stack)
{
    while (stack)
    {
        if (stack->content)
            ft_printf("%d ", stack->content);
        else
            ft_printf("0 ");
        stack = stack->next;
    }
}

int ft_find_min(t_stack **stack)
{
    t_stack *tmp;
    int     min;

    if (!stack || !*stack)
        return (0);
    tmp = *stack;
    min = tmp->content;
    while (tmp)
    {
        if (tmp->content < min)
            min = tmp->content;
        tmp = tmp->next;
    }
    return (min);
}

t_bool  ft_stack_is_sorted(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (FALSE);
        tmp = tmp->next;
    }
    return (TRUE);
}

int	ft_stacksize(t_stack *stack)
{
    t_stack *tmp;
    int     size;
    
    if (stack)
    {
        size = 1;
        tmp = stack;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            size++;
        }
        return (size);
    }
    else
        return (1);
}
