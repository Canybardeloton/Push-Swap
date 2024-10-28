/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:22:40 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:07 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free((void *)lst);
}
/*
t_list	*nex_lst(char *content)
{
	t_list	*tab;

	tab = (t_list *)malloc(sizeof(t_list));
	if (!tab)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}

void	ft_free(void *str)
{
	free(str);
}

int	main(void)
{
	char	content[] = "hello";

	ft_lstdelone(nex_lst(content), &ft_free);
}
*/
