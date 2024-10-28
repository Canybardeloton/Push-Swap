/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:25:48 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/11 10:56:35 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **listA, int nb)
{
	t_stack	*front;

	if (!*listA)
		return ;
	front = (*listA);
	*listA = (*listA)->next;
	front->next = (*listA)->next;
	(*listA)->next = front;
	if (nb == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **listB, int nb)
{
	t_stack	*front;

	if (!*listB)
		return ;
	front = (*listB);
	*listB = (*listB)->next;
	front->next = (*listB)->next;
	(*listB)->next = front;
	if (nb == 0)
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack **listA, t_stack **listB)
{
	if (!*listA || !*listB)
		return ;
	swap_a(listA, 1);
	swap_b(listB, 1);
	write(1, "ss\n", 3);
}
