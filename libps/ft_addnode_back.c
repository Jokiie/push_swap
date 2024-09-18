/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnode_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:57:04 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 19:05:18 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put the new node at the end of the stack
void	ft_addnode_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
		*stack = new_node;
	else if (stack && new_node)
	{
		last = ft_lastnode(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}
