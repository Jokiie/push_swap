/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:10:44 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/17 17:53:26 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [ ] to do : condition when a number is bigger than the max int
// [ ] to do : condition when a number is smaller than the min int
// [ ] to do : condition to handle the case the argument is mixed with strings and int
// [ ] to do : condition to check that no sign is used directly after a number 
// [x] to do : condition to check is there are multiple same numbers(same value) ex: 22 22
int    ft_check_nbr(long int nbr)
{
    if ((long int)nbr > 2147483647 || (long int)nbr < -2147483648)
        return (1);
    return (0);
}

int    ft_isinvalid_char(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isalpha(str[i]))
            return (1);
        // if the char is a digit and the next char is not a space
        // if (ft_isdigit(str[i]) && str[i + 1] != ' ')
        //     return (1);
        // if the char is not a digit, a space a '+' or a '-'
        if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
            return (1);
        // if the first character is a space
        if (i == 0 && str[0] == ' ')
            return (1);
        // if the char is a '-' and the next char is a '-'
        if ((str[i] == '-' || str[i] == '+') 
            && (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == ' '))
            return (1);
        // if the char is a space and the next char is a space
        if (str[i] == ' ' && str[i + 1] == ' ')
            return (1);
        // if the last char is not a digit
        if (!ft_isdigit(str[i]) && str[i + 1] == '\0')
            return (1);
        // if a space is following a '-'
        if ((str[i] == '-' || str[i] == '+' ) && str[i + 1] == ' ')
            return (1);
        i++;
    }
    return (0);
}

int    ft_check_duplicate(int argc, char **argv, int i)
{
    int j;

    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int    ft_check_args(int argc, char **argv, int i)
{
    while (i < argc)
    {
        if (ft_isinvalid_char(argv[i]) == 1)
        {
            ft_perror("Error\n");
            return (1);
        }
        if (ft_check_nbr(ft_atoi(argv[i])) == 1)
        {
            ft_perror("Error\n");
            return (1);
        }
        if (ft_check_duplicate(argc, argv, i) == 1)
        {
            ft_perror("Error\n");
            return (1);
        }
        i++;
    }
    return (0);
}
