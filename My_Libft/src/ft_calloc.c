/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:18:28 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/03 16:09:42 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb != 0 && ((SIZE_MAX / nmemb) < size))
		return (NULL);
	tab = (char *)malloc(size * nmemb);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
