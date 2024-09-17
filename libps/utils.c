/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:19:08 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/13 13:30:05 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_printf_stack_content(t_stack *stack)
{
    while (stack)
    {
        if (stack->content)
            ft_printf("%d, ", stack->content);
        else
            ft_printf("0, ");
        stack = stack->next;
    }
}

int    ft_count_args(char **args)
{
    int count;

    count = 0;
    while (args[count])
        count++;
    return (count);
}

int	ft_tabsize(int *tab)
{
	int size;
	
	size = 0;
	while (*tab)
	{
		size++;
		tab++;
	}
	return (size);
}
