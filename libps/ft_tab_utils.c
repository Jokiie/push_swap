/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:09:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 19:27:44 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_tab_is_sorted(int *tab, int size, int i)
{
    int j;

    j = i + 1;
    while (i < size && j < size)
    {
        if (tab[i++] > tab[j++])
            return (FALSE);
    }
    return (TRUE);
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
