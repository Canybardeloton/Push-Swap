/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:53:28 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/27 16:32:06 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **listA, t_stack **listB)
{
	t_stack	*top;

	if (!listB || !*listB)
		return ;
	top = *listB;
	*listB = (*listB)->next;
	top->next = *listA;
	*listA = top;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **listA, t_stack **listB)
{
	t_stack	*top;

	if (!listA || !*listA)
		return ;
	top = *listA;
	*listA = (*listA)->next;
	top->next = *listB;
	*listB = top;
	write(1, "pb\n", 3);
}
