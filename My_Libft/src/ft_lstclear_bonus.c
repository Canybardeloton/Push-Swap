/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:08:42 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:04 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tab;
	t_list	*next;

	if (!lst || !del || !*lst)
		return ;
	tab = *lst;
	while (tab != NULL)
	{
		next = tab->next;
		((*del)(tab->content));
		free((void *)tab);
		tab = next;
	}
	*lst = NULL;
}
