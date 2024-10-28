/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:50:34 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:41 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tab;
	const unsigned char	*mall;

	tab = (unsigned char *)dest;
	mall = (const unsigned char *)src;
	if (tab == mall || n == 0)
		return (dest);
	if (tab < mall)
	{
		i = -1;
		while (++i < n)
			tab[i] = mall[i];
	}
	else if (tab > mall)
	{
		i = n;
		while (i-- > 0)
			tab[i] = mall[i];
	}
	return (tab);
}
