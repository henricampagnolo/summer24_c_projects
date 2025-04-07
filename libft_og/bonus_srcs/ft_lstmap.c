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

static t_list	*ft_lstcpy(t_list *lst, void (*del)(void *))
{
	t_list	*result;
	t_list	*curr_node;
	t_list	*new;

	result = 0;
	curr_node = lst;
	while (curr_node)
	{
		new = ft_lstnew(0);
		if (!new)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		curr_node = curr_node->next;
	}
	return (result);
}

static void	ft_replace_vals(t_list *lst, t_list *cpylst, void *(*f)(void *))
{
	t_list	*curr_node_og;
	t_list	*curr_node_nw;

	curr_node_og = lst;
	curr_node_nw = cpylst;
	while (curr_node_og)
	{
		curr_node_nw->content = f(curr_node_og->content);
		curr_node_og = curr_node_og->next;
		curr_node_nw = curr_node_nw->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;

	if (!lst)
		return (0);
	result = ft_lstcpy(lst, del);
	if (!result)
		return (0);
	ft_replace_vals(lst, result, f);
	return (result);
}