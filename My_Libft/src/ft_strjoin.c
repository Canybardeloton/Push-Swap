/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:15:07 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 16:24:33 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*tab;

	i = 0;
	len = 0;
	while (s1[i])
		i++;
	while (s2[len])
		len++;
	tab = (char *)malloc(sizeof(char) * (i + len + 1));
	if (!tab)
		return (NULL);
	i = -1;
	len = -1;
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[++len])
		tab[i + len] = s2[len];
	tab[i + len] = '\0';
	return (tab);
}
