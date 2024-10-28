/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:04:20 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:27:49 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

static size_t	ft_strlensub(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlensub(s))
		len = 0;
	else if (ft_strlensub(s) - start < len)
		len = ft_strlensub(s) - start;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
	{
		while (s[start] && len - i > 0)
		{
			tab[i] = s[start];
			start++;
			i++;
		}
	}
	tab[i] = '\0';
	return (tab);
}
