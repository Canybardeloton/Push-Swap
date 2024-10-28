/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:42:15 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:32 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tab;
	size_t				i;

	i = 0;
	tab = (const unsigned char *)s;
	while (i < n)
	{
		if (tab[i] == (unsigned char)c)
			return (&((void *)tab)[i]);
		i++;
	}
	return (NULL);
}
