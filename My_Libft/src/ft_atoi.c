/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:05:43 by agiliber          #+#    #+#             */
/*   Updated: 2024/08/28 14:15:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	test;

	i = 0;
	sign = 1;
	test = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		test = test * 10 + s[i] - '0';
		i++;
	}
	if (test > 2147483647 || test * -1 < -2147483648)
		return (0);
	return (test * sign);
}
