/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:53:23 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/20 01:32:53 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node
t_stack	*ft_newnode(int *content)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	if (content == 0)
		node->content = 0;
	else
		node->content = *content;
	node->next = NULL;
	return (node);
}

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

// Return a pointer to the last node in the stack.
t_stack	*ft_lastnode(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = NULL;
	if (stack != NULL)
	{
		last = stack;
		while (last->next != NULL)
			last = last->next;
	}
	return (last);
}
