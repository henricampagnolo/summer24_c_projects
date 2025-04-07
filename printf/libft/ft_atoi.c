/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/18 22:53:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(int n, int start, int end)
{
	return (n >= start && n <= end);
}

static int	is_whitespace(int n)
{
	return (n == ' ' || is_in(n, '\t', '\r'));
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		n;
	int		sign;

	str = (char *) nptr;
	n = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = 10 * n + *str - '0';
		str++;
	}
	return (n * sign);
}
