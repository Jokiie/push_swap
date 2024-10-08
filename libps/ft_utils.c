/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:40:38 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/21 01:08:37 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}

int	ft_isplusminus(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isallowed_char(char c)
{
	return (ft_isdigit(c) || ft_isplusminus(c) || c == ' ');
}

int	ft_argsize(int argc, char **args)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = len + ft_strlen(args[i]);
		if (i < (argc - 1))
			len += 1;
		i++;
	}
	return (len);
}
