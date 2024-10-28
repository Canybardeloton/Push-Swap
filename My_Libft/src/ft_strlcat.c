/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:23:04 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:27:22 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	len_src = 0;
	i = 0;
	while (src[len_src])
		len_src++;
	while (dest[len_dest] && len_dest < n)
		len_dest++;
	if (n == 0 || n <= len_dest)
		return (n + len_src);
	while (src[i] && (len_dest + i) < (n - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
