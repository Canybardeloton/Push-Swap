/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:38:51 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/10 10:30:28 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_swap_rra(t_stack **list)
{
	swap_a(list, CW);
	reverse_rotate_rra(list, CW);
}

void	norm_swap_ra(t_stack **list)
{
	swap_a(list, CW);
	rotate_a(list, CW);
}

int	ft_lstsize_push(t_stack *lst)
{
	int		count;
	t_stack	*tmp;

	if (!lst)
		return (INT_MAX);
	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	final_twist_a(t_stack **listA)
{
	t_stack	*head_a;

	head_a = *listA;
	if (!ft_check_if_sorted_list(*listA))
	{
		initiate_struc_a(*listA);
		while (head_a->content != find_min_content(*listA))
			head_a = head_a->next;
		if (head_a->index < calculate_median(*listA))
		{
			while (find_position(head_a->content, *listA) > 1)
				rotate_a(listA, CW);
		}
		else
		{
			while (find_position(head_a->content, *listA) > 1)
				reverse_rotate_rra(listA, CW);
		}
	}
}
