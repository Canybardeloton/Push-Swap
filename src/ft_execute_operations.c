/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:40:51 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/10 10:47:23 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_solve_5(int ac, t_stack **listA, t_stack **listB)
{
	if (ac == 2)
		swap_a(listA, CW);
	else if (ac == 3)
		solve_stack_3(listA);
	else
	{
		while (ft_lstsize_push(*listA) > 3)
			push_b(listA, listB);
		solve_stack_3(listA);
		sort_stack_a(listA, listB);
	}
}
