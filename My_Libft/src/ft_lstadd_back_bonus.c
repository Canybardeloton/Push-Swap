/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:12:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:25:57 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tab;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tab = *lst;
	while (tab->next != NULL)
	{
		tab = tab->next;
	}
	tab->next = new;
}
