/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:09:10 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/13 13:47:37 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_tab_is_sorted(int *tab, int size)
{
    int i;
    int j;
    int last;

    
    i = 0;
    j = i + 1;
    last = size - 1;
    while (i < size && j < size)
    {
        if (tab[i] < tab[j])
        {
            i++;
            j++;
        }
        else
            return (FALSE);   
    }
    ft_printf("Stack is already sorted.\n");
    return (TRUE);
}
