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

static int	ft_getlen(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	putnubr(long int n, char *str)
{
	if (n >= 10)
		putnubr(n / 10, str - 1);
	n = n % 10 + '0';
	*str = n;
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nt;

	nt = n;
	size = ft_getlen(nt);
	str = ft_calloc((size + 1), sizeof(char));
	if (str == 0)
		return (0);
	if (nt <= 0)
	{
		if (nt == 0)
			*str = 0;
		else
			*str = '-';
		nt *= -1;
	}
	putnubr(nt, str + size - 1);
	return (str);
}
