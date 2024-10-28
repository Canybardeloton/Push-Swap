/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:42:33 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 16:37:42 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(int nbr, t_stack *list)
{
	t_stack	*head;
	int		count;

	if (!list)
		return (-1);
	count = 1;
	head = list;
	while (head != NULL)
	{
		if (head->content == nbr)
			return (count);
		count++;
		head = head->next;
	}
	return (-1);
}

int	find_min_content(t_stack *list)
{
	int		i;
	t_stack	*tmp;

	if (!list)
		return (-1);
	tmp = list;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content < i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	find_min(t_stack *list)
{
	int		i;
	t_stack	*tmp;
	int		index;

	if (!list)
		return (-1);
	tmp = list;
	i = tmp->price;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->price < i)
		{
			i = tmp->price;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	find_max(t_stack *list)
{
	int		i;
	t_stack	*tmp;

	if (!list)
		return (INT_MAX);
	tmp = list;
	i = tmp->content;
	while (tmp)
	{
		if (tmp->content > i)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}
