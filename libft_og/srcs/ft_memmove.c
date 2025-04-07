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

static int	greater_than(char *p1, char *p2)
{
	long	l1;
	long	l2;

	l1 = (long) p1;
	l2 = (long) p2;
	return (l1 >= l2);
}

static void	*ft_inv_memcpy(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;
	size_t	i;

	p_src = (char *) src;
	p_dest = (char *) dest;
	p_src += n - 1;
	p_dest += n - 1;
	i = 0;
	while (i < n)
	{
		*p_dest = *p_src;
		p_src--;
		p_dest--;
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;

	p_src = (char *) src;
	p_dest = (char *) dest;
	if (greater_than(p_src, p_dest))
		ft_memcpy(p_dest, p_src, n);
	else
		ft_inv_memcpy(p_dest, p_src, n);
	return (dest);
}
