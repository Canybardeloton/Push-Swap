/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:02:19 by agiliber          #+#    #+#             */
/*   Updated: 2024/07/03 14:07:39 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

static char	**free_all(char **s, int index)
{
	while (index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
	return (NULL);
}

static int	word(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_strdupsplit(const char *s, int limit)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (limit + 1));
	if (!dest)
		return (free(dest), NULL);
	i = 0;
	while (i < limit)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_splitnorm(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && (s[i] == c))
			i++;
		while (s[i + j] && (s[i + j] != c))
			j++;
		if (j > 0)
		{
			tab[k] = ft_strdupsplit(&s[i], j);
			if (!tab[k])
				return (free_all(tab, k - 1));
			k++;
		}
		i += j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s && c == '\0')
		return (NULL);
	len = word(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	return (ft_splitnorm(tab, s, c));
}
