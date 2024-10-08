/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:10:44 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/21 01:24:29 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

int	ft_check_nbr(const char *str)
{
	long int	nbr;

	nbr = ft_atol(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	return (0);
}

int	ft_isinvalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i + 1])
		{
			if (ft_isplusminus(str[i + 1]) || ft_isalpha(str[i + 1]))
				return (1);
		}
		if (ft_isalpha(str[i]))
			return (1);
		if (!ft_isallowed_char(str[i]))
			return (1);
		if (ft_isplusminus(str[i])
			&& (ft_isplusminus(str[i + 1]) || str[i + 1] == ' '))
			return (1);
		i++;
	}
	if (ft_isplusminus(str[i - 1]))
		return (1);
	return (0);
}

int	ft_check_duplicate(int argc, char **argv, int i)
{
	int	j;

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

int	ft_check_args(int argc, char **argv, int i)
{
	while (i < argc)
	{
		if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
		{
			ft_perror("Error\n");
			return (1);
		}
		if (ft_isinvalid_char(argv[i]) == 1)
		{
			ft_perror("Error\n");
			return (1);
		}
		if (ft_check_nbr(argv[i]) == 1)
		{
			ft_perror("Error\n");
			return (1);
		}
		i++;
	}
	if (ft_check_duplicate(argc, argv, 0) == 1)
	{
		ft_perror("Error\n");
		return (1);
	}
	return (0);
}
