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

static char	int_to_char(int n)
{
	return (n & 255);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	c = int_to_char(c);
	i = 0;
	str = (char *) s;
	while (str[i] != c && str[i] != 0)
		i++;
	if (str[i] == c)
		return (str + i);
	return (0);
}
