/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:49:34 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:38 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tab;
	const unsigned char	*mall;

	if (dest == NULL && src == NULL)
		return (NULL);
	tab = (unsigned char *)dest;
	mall = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tab[i] = mall[i];
		i++;
	}
	return (tab);
}
