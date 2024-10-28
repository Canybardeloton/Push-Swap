/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:27:11 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/30 18:21:35 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_digits(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (FALSE);
	while (str[i])
	{
		if ((str[i] > 32 && str[i] < 43)
			|| (str[i] > 45 && str[i] < 48)
			|| (str[i] > 57 && str[i] <= 127)
			|| (str[i] == 44))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

bool	check_signs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] == '+')
			return (FALSE);
		else if (str[i] == '+' && str[i + 1] == '-')
			return (FALSE);
		else if (str[i] == '-' && str[i + 1] == '+')
			return (FALSE);
		else if (str[i] == '-' && str[i + 1] == '-')
			return (FALSE);
		else if (str[i] == '+' && str[i + 1] == '\0')
			return (FALSE);
		else if (str[i] == '-' && str[i + 1] == '\0')
			return (FALSE);
		else if (str[i] == '-' && is_num(str[i + 1]) == FALSE)
			return (FALSE);
		else if (str[i] == '+' && is_num(str[i + 1]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

bool	check_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 48)
		i++;
	if (ft_strlen(&str[i]) < 12)
		return (TRUE);
	return (FALSE);
}

bool	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (FALSE);
	return (TRUE);
}
