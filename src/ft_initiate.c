/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:18:11 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/31 09:55:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_struc_b(t_stack *listA, t_stack *listB)
{
	t_stack	*head_b;
	t_stack	*head_a;
	int		size;

	head_b = listB;
	head_a = listA;
	set_target_b(listA, listB);
	while (head_b)
	{
		(head_b)->index = find_position((head_b)->content, listB);
		(head_b)->median = own_median(head_b->index, listB);
		size = ft_lstsize_push(listB);
		(head_b)->price = best_move_btoa(size, head_a, head_b);
		head_b = head_b->next;
	}
}

void	initiate_struc_a(t_stack *listA)
{
	t_stack	*head_a;

	head_a = listA;
	while (head_a)
	{
		(head_a)->index = find_position((head_a)->content, listA);
		(head_a)->median = own_median(head_a->index, listA);
		head_a = head_a->next;
	}
}

int	find_target(int nbr, t_stack *listA)
{
	t_stack	*head_a;
	int		diff;
	int		closest;
	int		limit;

	head_a = listA;
	limit = INT_MAX;
	while (head_a)
	{
		diff = head_a->content - nbr;
		if (diff < 0)
			diff *= -1;
		if (diff < limit)
		{
			limit = diff;
			closest = head_a->index;
		}
		head_a = head_a->next;
	}
	return (closest);
}

void	set_target_b(t_stack *listA, t_stack *listB)
{
	t_stack	*head_b;
	t_stack	*head_a;
	int		closest;

	head_b = listB;
	closest = 0;
	while (head_b)
	{
		closest = find_target(head_b->content, listA);
		head_a = listA;
		while (head_a)
		{
			if (head_a->index == closest)
			{
				head_b->target = head_a;
				head_b->targ_index = head_a->index;
				break ;
			}
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}
