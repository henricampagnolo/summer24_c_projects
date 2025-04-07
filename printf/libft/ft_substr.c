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

static int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s0;
	char	*dest;
	int		size;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	s0 = ((char *) s) + start;
	size = min(ft_strlen(s0), len) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s0, size);
	return (dest);
}
