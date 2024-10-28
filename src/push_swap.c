/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:07:03 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/10 10:44:50 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_algo(int ac, t_stack **list_a, t_stack **list_b)
{
	t_stack	*head_b;

	if (!list_a || !*list_a)
		return ;
	if (ac <= 5)
	{
		execute_solve_5(ac, list_a, list_b);
		final_twist_a(list_a);
	}
	else
	{
		head_b = *list_b;
		list_b = ft_initiate_list_b(list_a, list_b);
		head_b = solve_stack_b(list_a, list_b);
		solve_stack_3(list_a);
		list_a = sort_stack_a(list_a, &head_b);
		final_twist_a(list_a);
	}
}

void	ft_print_list(t_stack *list)
{
	int		count;
	t_stack	*tmp;

	count = 1;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	t_stack	*list_a;
	t_stack	*list_b;
	int		i;

	if (ac > 1)
	{
		i = 0;
		list_a = NULL;
		list_b = NULL;
		if (!ft_check_split_tab(av))
			return (write(2, "Error\n", 6), 0);
		tab = fill_tab(ac, av);
		if (tab[1] == NULL)
			return (free_all_lst(tab), 0);
		if (ft_check_if_sorted(tab) == FALSE)
			return (free_all_lst(tab), 0);
		ft_fill_list(tab, &list_a);
		if (check_double(&list_a) == FALSE)
			return (ft_lstclear_push(&list_a, del), write(2, "Error\n", 6), 0);
		i = ft_lstsize_push(list_a);
		solve_algo(i, &list_a, &list_b);
		ft_lstclear_push(&list_a, del);
	}
	return (0);
}
