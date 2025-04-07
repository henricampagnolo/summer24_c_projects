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

#include "../printf.h"

static void	del(void *v)
{
	if (v)
		free(v);
}

void	*ft_callocplus(size_t size)
{
	void	*result;
	t_list	*new_space;

	result = calloc(size, 1);
	if (!result)
	{
		ft_lstclear(&g_free_mallocs, del);
		return (0);
	}
	new_space = ft_lstnew(result);
	if (!new_space)
	{
		ft_lstclear(&g_free_mallocs, del);
		free(result);
		return (0);
	}
	ft_lstadd_back(&g_free_mallocs, ft_lstnew(result));
	return (result);
}