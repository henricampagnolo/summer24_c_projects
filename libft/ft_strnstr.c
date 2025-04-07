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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;
	size_t	i;
	int		valid;
	char	*cpy_hay;

	i = 0;
	cpy_hay = (char *) haystack;
	needle_size = ft_strlen(needle);
	if (needle_size == 0)
		return (cpy_hay);
	if (len == 0)
		return (0);
	while (cpy_hay[i] != 0 && i < len - needle_size + 1)
	{
		valid = ft_strncmp(cpy_hay + i, needle, needle_size);
		if (valid == 0)
			return (cpy_hay + i);
		i++;
	}
	return (0);
}
