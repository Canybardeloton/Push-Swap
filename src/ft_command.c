/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:11:52 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/06 13:44:50 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rra_rrb(int content, t_stack **listA, t_stack **listB)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = *listB;
	head_a = *listA;
	while (head_b->content != content)
		head_b = head_b->next;
	while (head_a && head_a->index < head_b->targ_index)
		head_a = head_a->next;
	while (find_position(content, *listB) > 1
		&& find_position(head_a->content, *listA) > 1)
		reverse_rotate_rrr(listA, listB);
	while (find_position(content, *listB) > 1)
		reverse_rotate_rrb(listB, CW);
	if (content > head_a->content)
	{
		while (find_position(head_a->content, *listA) < ft_lstsize_push(*listA))
			reverse_rotate_rra(listA, CW);
	}
	else
	{
		while (find_position(head_a->content, *listA) > 1)
			reverse_rotate_rra(listA, CW);
	}
	push_a(listA, listB);
}

void	execute_ra_rb(int content, t_stack **listA, t_stack **listB)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = *listB;
	head_a = *listA;
	while (head_b->content != content)
		head_b = head_b->next;
	while (head_a && head_a->index < head_b->targ_index)
		head_a = head_a->next;
	while (find_position(content, *listB) > 1
		&& find_position(head_a->content, *listA) > 1)
		rotate_rr(listA, listB);
	while (find_position(content, *listB) > 1)
		rotate_b(listB, CW);
	if (content > head_a->content)
	{
		while (find_position(head_a->content, *listA) < ft_lstsize_push(*listA))
			rotate_a(listA, CW);
	}
	else
	{
		while (find_position(head_a->content, *listA) > 1)
			rotate_a(listA, CW);
	}
	push_a(listA, listB);
}

void	execute_ra_rrb(int content, t_stack **listA, t_stack **listB)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = *listB;
	head_a = *listA;
	while (head_b->content != content)
		head_b = head_b->next;
	while (head_a && head_a->index < head_b->targ_index)
		head_a = head_a->next;
	if (content > head_a->content)
	{
		while (find_position(head_a->content, *listA) < ft_lstsize_push(*listA))
			rotate_a(listA, CW);
	}
	else
	{
		while (find_position(head_a->content, *listA) > 1)
			rotate_a(listA, CW);
	}
	while (find_position(content, *listB) > 1)
		reverse_rotate_rrb(listB, CW);
	push_a(listA, listB);
}

void	execute_rra_rb(int content, t_stack **listA, t_stack **listB)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = *listB;
	head_a = *listA;
	while (head_b->content != content)
		head_b = head_b->next;
	while (head_a && head_a->index < head_b->targ_index
		&& head_a->index < ft_lstsize_push(*listA))
		head_a = head_a->next;
	while (find_position(content, *listB) > 1)
		rotate_b(listB, CW);
	if (content > head_a->content)
	{
		while (find_position(head_a->content, *listA) < ft_lstsize_push(*listA))
			reverse_rotate_rra(listA, CW);
	}
	else if (content < head_a->content)
	{
		while (find_position(head_a->content, *listA) > 1)
			reverse_rotate_rra(listA, CW);
	}
	push_a(listA, listB);
}
