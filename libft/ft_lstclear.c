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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr_node;
	t_list	*last_node;

	curr_node = *lst;
	while (curr_node)
	{
		last_node = curr_node;
		curr_node = curr_node->next;
		ft_lstdelone(last_node, del);
	}
	*lst = 0;
}
