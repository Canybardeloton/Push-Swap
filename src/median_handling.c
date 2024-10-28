/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:15:44 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/10 10:52:54 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_median(t_stack *list)
{
	int	size;
	int	median;

	size = ft_lstsize_push(list);
	if (size == 5)
		median = (size / 2) + 1;
	else
		median = size / 2;
	return (median);
}

bool	own_median(int index, t_stack *list)
{
	if (ft_lstsize_push(list) == 1)
		return (UNDER);
	if (ft_lstsize_push(list) == 3)
	{
		if (index < 2)
			return (UNDER);
		return (ABOVE);
	}
	if (ft_lstsize_push(list) % 2 != 0)
	{
		if (index <= (calculate_median(list) + 1))
			return (UNDER);
		else
			return (ABOVE);
	}
	else
	{
		if (index > calculate_median(list))
			return (ABOVE);
		else
			return (UNDER);
	}
}

t_stack	*ft_lstlast_push(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
