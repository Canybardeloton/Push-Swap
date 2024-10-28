/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:31:55 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/20 15:28:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

int	ft_putnbr_base_un(unsigned int nb)
{
	unsigned int	tab[256];
	int				i;
	int				len;
	int				j;
	char			*base;

	i = 0;
	j = 0;
	if (nb == 0)
		j += (ft_putchar_print('0'));
	else if (nb > 0)
	{
		base = "0123456789";
		len = ft_strlen(base);
		while (nb > 0)
		{
			tab[i] = nb % len;
			nb = nb / len;
			i++;
		}
		while (i-- > 0)
			j += ft_putchar_print(base[tab[i]]);
	}
	return (j);
}
