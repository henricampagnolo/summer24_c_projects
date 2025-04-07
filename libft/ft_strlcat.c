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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	count;
	size_t	src_size;

	count = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (size + src_size);
	while ((src[count] != '\0') && (count + dst_size < size - 1))
	{
		dst[dst_size + count] = src[count];
		count++;
	}
	dst[dst_size + count] = '\0';
	if (dst_size < size)
		return (dst_size + src_size);
	return (size + src_size);
}
