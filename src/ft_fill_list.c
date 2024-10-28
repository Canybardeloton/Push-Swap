/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:02:10 by agiliber          #+#    #+#             */
/*   Updated: 2024/09/04 09:47:09 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	convert_to_int(char *tab_split)
{
	long	nb;

	if (!tab_split)
		return (FALSE);
	nb = ft_atol(tab_split);
	if (nb < -2147483648 || nb > INT_MAX)
		return (FALSE);
	return (nb);
}

char	*ft_join_push(int count, char **input)
{
	int		i;
	char	*tmp;
	char	*tab;

	i = 0;
	tab = ft_strdup("");
	if (!tab)
		return (free(tab), NULL);
	while (count > 1 && i++ < count - 1)
	{
		tmp = ft_strjoin(tab, input[i]);
		free(tab);
		if (!tmp)
			return (free(tab), free(tmp), tab = NULL, NULL);
		tab = tmp;
		if (i < count - 1)
		{
			tmp = ft_strjoin(tab, " ");
			free(tab);
			if (!tmp)
				return (free(tab), tab = NULL, NULL);
			tab = tmp;
		}
	}
	return (tab);
}

char	**fill_tab(int count, char **input)
{
	char	*tab_join;
	char	**tab_split;

	if (count == 2)
		tab_join = ft_strdup(input[1]);
	else
	{
		tab_join = ft_join_push(count, input);
		if (!tab_join)
			return (NULL);
	}
	return (tab_split = ft_split(tab_join, ' '), free(tab_join), tab_split);
}

void	ft_fill_list(char **tab_split, t_stack **list)
{
	t_stack	*struc;
	int		index;

	index = 0;
	while (tab_split[index])
	{
		struc = ft_newlst(list, convert_to_int(tab_split[index]));
		if (!struc)
		{
			ft_lstclear_push(list, del);
			free_all_lst(tab_split);
			return ;
		}
		ft_lstadd_back_push(list, struc);
		index++;
	}
	free_all_lst(tab_split);
}
