/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorythm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:43:56 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 16:29:29 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_initiate_list_b(t_stack **listA, t_stack **listB)
{
	if (!listA || !*listA || !listB)
		return (NULL);
	push_b(listA, listB);
	push_b(listA, listB);
	if ((*listB)->content < (*listB)->next->content)
		swap_b(listB, CW);
	return (listB);
}

void	solve_stack_3(t_stack **listA)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*third;

	if (!listA || !*listA)
		return ;
	head = *listA;
	second = head->next;
	third = second->next;
	if (head->content > second->content && second->content < third->content
		&& head->content < third->content)
		swap_a(listA, CW);
	else if (head->content > second->content && second->content > third->content
		&& head->content > third->content)
		norm_swap_rra(listA);
	else if (head->content > second->content && second->content < third->content
		&& head->content > third->content)
		rotate_a(listA, CW);
	else if (head->content < second->content && second->content > third->content
		&& head->content < third->content)
		norm_swap_ra(listA);
	else if (head->content < second->content && second->content > third->content
		&& head->content > third->content)
		reverse_rotate_rra(listA, CW);
}

t_stack	*solve_stack_b(t_stack **listA, t_stack **listB)
{
	if (!listA || !*listA)
		return (NULL);
	while (ft_lstsize_push(*listA) > 3 && !ft_check_if_sorted_list(*listA))
		push_b(listA, listB);
	return (*listB);
}

t_stack	**sort_stack_a(t_stack **listA, t_stack **listB)
{
	t_stack	*head_b;

	if (!listA || !*listA || !listB || !*listB)
		return (NULL);
	while (*listB != NULL)
	{
		initiate_struc_a(*listA);
		initiate_struc_b(*listA, *listB);
		head_b = *listB;
		while (head_b->index != find_min(*listB))
			head_b = head_b->next;
		if (head_b)
		{
			if (head_b->best_move == 2)
				execute_rra_rrb((head_b)->content, listA, listB);
			else if (head_b->best_move == -2)
				execute_ra_rb((head_b)->content, listA, listB);
			else if (head_b->best_move == -1)
				execute_ra_rrb((head_b)->content, listA, listB);
			else if (head_b->best_move == 1)
				execute_rra_rb((head_b)->content, listA, listB);
		}
	}
	return (listA);
}
