/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:53:22 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/30 15:19:40 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_rra(t_stack **listA, int nb)
{
	t_stack	*last;
	t_stack	*head;

	if (!listA || !*listA || !(*listA)->next)
		return ;
	last = (*listA);
	head = NULL;
	while (last->next != NULL)
	{
		head = last;
		last = last->next;
	}
	if (head)
		head->next = NULL;
	last->next = *listA;
	(*listA) = last;
	if (nb == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_rrb(t_stack **listB, int nb)
{
	t_stack	*last;
	t_stack	*head;

	if (!listB || !*listB || !(*listB)->next)
		return ;
	last = (*listB);
	head = NULL;
	while (last->next != NULL)
	{
		head = last;
		last = last->next;
	}
	if (head)
		head->next = NULL;
	last->next = *listB;
	*listB = last;
	if (nb == 0)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rrr(t_stack **listA, t_stack **listB)
{
	if (!*listA || !*listB)
		return ;
	reverse_rotate_rra(listA, 1);
	reverse_rotate_rrb(listB, 1);
	write(1, "rrr\n", 4);
}
