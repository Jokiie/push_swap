
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:44:49 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 17:51:43 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lastnode(t_stack *stack)
{
	t_stack *last;

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