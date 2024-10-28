/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:28 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/04 09:53:26 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	res = res * sign;
	if (res < -2147483648 || res > INT_MAX)
		return (2147483650);
	return (res);
}

void	ft_lstclear_push(t_stack **list, void (*del)(int))
{
	t_stack	*next;

	if (!*list || !list)
		return ;
	while (*list != NULL)
	{
		next = (*list)->next;
		del((*list)->content);
		free(*list);
		(*list) = next;
	}
	*list = NULL;
}

void	ft_lstadd_front_push(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back_push(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while ((current)->next != NULL)
		(current) = (current)->next;
	(current)->next = new;
}

t_stack	*ft_newlst(t_stack **list, int content)
{
	t_stack	*new;

	if (list == NULL)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
