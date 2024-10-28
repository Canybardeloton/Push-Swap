/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:53:31 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/18 15:08:44 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **listA, int nb)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*listA || !(*listA)->next)
		return ;
	first = (*listA);
	second = first->next;
	last = (*listA);
	while (last->next != NULL)
		last = last->next;
	(*listA) = second;
	last->next = first;
	first->next = NULL;
	if (nb == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **listB, int nb)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!listB || !*listB || !(*listB)->next)
		return ;
	first = (*listB);
	second = first->next;
	last = (*listB);
	while (last->next != NULL)
		last = last->next;
	(*listB) = second;
	last->next = first;
	first->next = NULL;
	if (nb == 0)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_stack **listA, t_stack **listB)
{
	if (!*listA || !*listB)
		return ;
	rotate_a(listA, 1);
	rotate_b(listB, 1);
	write(1, "rr\n", 3);
}
