/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:37:36 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:16 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*chain;

	if (!lst || !f || !del)
		return (NULL);
	chain = NULL;
	while (lst != NULL)
	{
		tab = (t_list *)malloc(sizeof(t_list));
		if (!tab)
		{
			ft_lstclear(&chain, del);
			return (NULL);
		}
		tab->content = f(lst->content);
		tab->next = NULL;
		ft_lstadd_back(&chain, tab);
		lst = lst->next;
	}
	return (chain);
}
