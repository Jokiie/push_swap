/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:48:51 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 17:50:20 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	unsigned int	nbr;
	int				i;
	int				j;
	int				min;

	min = ft_find_min(stack_a);
	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < size)
		{
			nbr = (unsigned int)(*stack_a)->content - min;
			if ((nbr >> i) & 1)
				ft_rotate_a(stack_a);
			else
				ft_push_a(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_push_b(stack_a, stack_b);
        i++;
	}
}
