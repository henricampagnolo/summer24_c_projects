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

#include "../libft.h"

static int	is_in(char c, char *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*dest;

	start = 0;
	while (is_in(s1[start], (char *) set) && s1[start] != 0)
		start++;
	end = ft_strlen(s1) - 1;
	while (is_in(s1[end], (char *) set) && s1[end] != 0)
		end--;
	size = (end - start + 1) * (end - start + 1 > 0) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1 + start, size);
	return (dest);
}
