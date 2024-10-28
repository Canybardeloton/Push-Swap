/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:01:41 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:25:53 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

static int	ft_size(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nb;
	int		i;

	nb = n;
	i = 0;
	tab = (char *)malloc(sizeof(char) * (ft_size(n) + 1));
	if (!tab)
		return (NULL);
	if (nb == 0)
		tab[0] = '0';
	else if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[ft_size(n) - i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	tab[ft_size(n)] = '\0';
	return (tab);
}
