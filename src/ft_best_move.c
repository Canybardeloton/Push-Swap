/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:52 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 16:21:17 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move_btoa(int size, t_stack *listA, t_stack *listB)
{
	int		best_move;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = listA;
	head_b = listB;
	best_move = 0;
	while (head_a->content != head_b->target->content)
		head_a = head_a->next;
	if (head_a->median == UNDER && head_b->median == UNDER)
		best_move = case_un_un(listA, listB);
	else if (head_a->median == ABOVE && head_b->median == ABOVE)
		best_move = case_ab_ab(size, listA, listB);
	else if (head_a->median == UNDER && head_b->median == ABOVE)
		best_move = case_un_ab(size, listB);
	else if (head_a->median == ABOVE && head_b->median == UNDER)
		best_move = case_ab_un(listA, listB);
	return (best_move);
}
