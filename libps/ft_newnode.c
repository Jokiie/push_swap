/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:27:06 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 17:50:32 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_newnode(int *content)
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
