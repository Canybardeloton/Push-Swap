/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:07 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/04 09:55:52 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_input(char *str)
{
	if (!str)
		return (FALSE);
	else if (check_digits(str) == FALSE)
		return (FALSE);
	else if (check_signs(str) == FALSE)
		return (FALSE);
	else if (check_length(str) == FALSE)
		return (FALSE);
	else if (check_spaces(str) == FALSE)
		return (FALSE);
	return (TRUE);
}

bool	ft_check_split_tab(char **tab_split)
{
	int	i;

	if (!tab_split)
		return (FALSE);
	i = 1;
	while (tab_split[i])
	{
		if (check_input(tab_split[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

bool	ft_check_if_sorted(char **tab_split)
{
	int	i;
	int	count;

	if (!tab_split)
		return (FALSE);
	i = 0;
	count = 2;
	while (tab_split[i])
	{
		if (ft_atol(tab_split[i]) == 2147483650)
			return (write(2, "Error\n", 6), 0);
		if (i > 0 && ft_atol(tab_split[i - 1]) == ft_atol(tab_split[i]))
			return (write(2, "Error\n", 6), FALSE);
		if (i > 0 && ft_atol(tab_split[i - 1]) > ft_atol(tab_split[i]))
			count = 1;
		if (i > 0 && ft_atol(tab_split[i - 1]) < ft_atol(tab_split[i])
			&& count != 1)
			count = 0;
		i++;
	}
	if (count == 0)
		return (FALSE);
	return (TRUE);
}

bool	ft_check_if_sorted_list(t_stack *list)
{
	int	nbr;

	nbr = list->content;
	while (list)
	{
		if (nbr > list->content)
			return (FALSE);
		nbr = list->content;
		list = list->next;
	}
	return (TRUE);
}

bool	check_double(t_stack **lst)
{
	t_stack	*after;
	t_stack	*current;

	if (*lst != NULL)
	{
		current = *lst;
		while (current != NULL)
		{
			after = current->next;
			while (after != NULL)
			{
				if ((current->content) == (after->content))
					return (FALSE);
				after = after->next;
			}
			current = current->next;
		}
		return (TRUE);
	}
	return (FALSE);
}
