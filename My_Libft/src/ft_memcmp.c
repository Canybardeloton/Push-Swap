/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:45:06 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:26:35 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tab1;
	const unsigned char	*tab2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	tab1 = (const unsigned char *)s1;
	tab2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
	}
	return (0);
}
