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

void	print_nums(void *v)
{
	ft_putnbr_fd((long)v, 1);
	ft_putchar_fd('\n', 1);
}

/*
*/
void	*f(void *c)
{
	return ((void *)((long)c / 2));
}

void	del(void *v)
{
	if (v)
		free(v);
}

void	*ft_calloc_plus(size_t size, t_list **ptrs)
{
	void	*result;

	result = calloc(size, 1);
	if (!result)
	{
		ft_lstclear(ptrs, del);
		return (0);
	}
	ft_lstadd_back(ptrs, ft_lstnew(result));
	return (result);
}

int	main(void)
{
	t_list	*all_mallocs;
	char	*funny;

	all_mallocs = 0;
	funny = ft_calloc_plus(50, &all_mallocs);
	funny[34] = '7';
	funny[2] = '!';
	ft_print_memory(funny, 40);

	ft_lstclear(&all_mallocs, del);
}
