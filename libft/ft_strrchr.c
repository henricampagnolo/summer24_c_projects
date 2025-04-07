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

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;
	char	*str;

	i = 0;
	c = int_to_char(c);
	str = (char *) s;
	if (!c)
		return (str + ft_strlen(str));
	pos = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			pos = str + i;
		i++;
	}
	return (pos);
}
