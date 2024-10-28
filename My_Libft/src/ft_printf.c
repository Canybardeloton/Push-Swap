/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:53:19 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/20 15:28:12 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int		tab[256];
	int					i;
	int					len;
	int					j;

	i = 0;
	j = 0;
	len = ft_strlen(base);
	if (nb == 0)
		return (j += ft_putchar_print('0'), j);
	if (nb < 0)
	{
		j += ft_putchar_print('-');
		nb *= -1;
	}
	while (nb)
	{
		tab[i] = nb % len;
		nb = nb / len;
		i++;
	}
	while (i-- > 0)
		j += ft_putchar_print(base[tab[i]]);
	return (j);
}

int	ft_print_format(char format, va_list ap)
{
	int	count;

	if (!format || !ap)
		return (0);
	count = 0;
	if (format == 'c')
		count += ft_putchar_print(va_arg(ap, int));
	if (format == 's')
		count += ft_putstr_print(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_print(va_arg(ap, int));
	else if (format == 'u')
		count += ft_putnbr_base_un(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		count += ft_putptr_print(va_arg(ap, void *));
	else if (format == '%')
		count += ft_putchar_print('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			i++;
			count += ft_print_format(format[i], ap);
		}
		else
			count += ft_putchar_print(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
