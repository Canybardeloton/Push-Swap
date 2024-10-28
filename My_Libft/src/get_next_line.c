/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:52 by agiliber          #+#    #+#             */
/*   Updated: 2024/06/18 15:37:10 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libft.h"

char	*go_to_next_line(char *tmp)
{
	int		i;
	char	*final_str;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0' || tmp[i + 1] == '\0')
		return (NULL);
	final_str = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	if (!final_str)
		return (NULL);
	tmp[i + 1] = '\0';
	return (final_str);
}

char	*ft_fill_buffer(char *final_str, int fd, char *buffer)
{
	int		ret;
	char	*tmp;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(final_str), NULL);
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		if (final_str == NULL)
			final_str = ft_strdup("");
		tmp = final_str;
		final_str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!final_str)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (final_str);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buffer;
	static char	*final_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(final_str), final_str = NULL, NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	tmp = ft_fill_buffer(final_str, fd, buffer);
	free(buffer);
	if (!tmp)
		return (free(final_str), final_str = NULL, NULL);
	final_str = go_to_next_line(tmp);
	return (tmp);
}
