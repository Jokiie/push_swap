/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:40:38 by ccodere           #+#    #+#             */
/*   Updated: 2024/09/20 12:54:38 by ccodere          ###   ########.fr       */
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
