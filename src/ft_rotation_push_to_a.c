/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_push_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:37:24 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/30 14:26:32 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_ab_ab(int size, t_stack *listA, t_stack *listB)
{
	t_stack	*head_b;
	t_stack	*head_a;
	int		count;

	head_b = listB;
	head_a = listA;
	if (size - head_b->index > \
		ft_lstsize_push(listA) - head_b->target->index)
	{
		head_b->best_move = 2;
		count = head_b->index;
		return (count);
	}
	else
	{
		head_b->best_move = 2;
		count = head_b->targ_index;
		return (count + 1);
	}
}

int	case_ab_un(t_stack *listA, t_stack *listB)
{
	int		target;
	int		count;
	int		index;
	int		max_a;

	count = 1;
	max_a = ft_lstsize_push(listA);
	index = listB->index;
	target = listB->target->index;
	if (index == 1 && target == 1)
		return (count);
	while (target < max_a)
	{
		target++;
		count++;
	}
	while (index > 1)
	{
		index--;
		count++;
	}
	listB->best_move = 1;
	return (count + 1);
}

int	case_un_ab(int size, t_stack *listB)
{
	int		count;
	int		index;
	int		position;

	count = 1;
	index = listB->targ_index;
	position = listB->index;
	while (index > 1)
	{
		index--;
		count++;
	}
	while (position < size)
	{
		position++;
		count++;
	}
	listB->best_move = -1;
	return (count + 1);
}

int	case_un_un(t_stack *listA, t_stack *listB)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		count;

	head_a = listA;
	head_b = listB;
	if (head_b->index > head_b->target->index)
	{
		head_b->best_move = -2;
		count = head_b->index;
		return (count + 1);
	}
	else
	{
		head_b->best_move = -2;
		count = head_b->targ_index;
		return (count);
	}
}
