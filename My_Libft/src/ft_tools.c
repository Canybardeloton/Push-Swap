/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:56:05 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/20 17:36:21 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

int	ft_putchar_print_print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_size_print(int n)
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

int	ft_putstr_print_print(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr_print("(null)"), 6);
	while (str[i])
	{
		ft_putchar_print(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_print(int n)
{
	int		len;

	len = ft_size_print(n);
	if (n == -2147483648)
		return ((write(1, "-2147483648", 11)), 11);
	if (n < 0)
	{
		ft_putchar_print('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_print(n / 10);
		ft_putnbr_print(n % 10);
	}
	else
		ft_putchar_print(n + '0');
	return (len);
}

int	ft_putptr_print_print_print(void *p)
{
	unsigned long	nb;
	unsigned int	tab[256];
	int				i;
	int				len;
	char			*base;

	nb = (unsigned long)p;
	base = "0123456789abcdef";
	i = 0;
	if (nb == 0)
		return (ft_putstr_print("(nil)"));
	len = ft_putstr_print("0x");
	while (nb > 0)
	{
		tab[i] = nb % 16;
		nb /= 16;
		i++;
	}
	while (i-- > 0)
		len += ft_putchar_print(base[tab[i]]);
	return (len);
}
