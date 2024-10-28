/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:30:40 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/03 18:09:10 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

static size_t	ft_strlentrim(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strchrtrim(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tab;
	size_t		k;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchrtrim(set, s1[i]) && s1[i])
		i++;
	j = ft_strlentrim(s1);
	while (j > i && ft_strchrtrim(set, s1[j - 1]))
		j--;
	tab = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!tab)
		return (NULL);
	while (i < j)
		tab[k++] = s1[i++];
	tab[k] = '\0';
	return (tab);
}
/*
int	main(void)
{
	char s1[] = "a";
	char set[] = "abcd";

	printf("%s\n", ft_strtrim(s1, set));
	printf("%lu\n", sizeof(ft_strtrim(s1, set)));
	return (0);
} */
