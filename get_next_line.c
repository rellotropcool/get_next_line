/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:41:30 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/23 15:23:04 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*big_str;
	char			*buffer;
	int				c;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(big_str), big_str = NULL, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	c = 1;
	while (c > 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		buffer[c] = 0;
		big_str = ft_strjoin(big_str, buffer);
		if (check_retour(big_str))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (aff_ligne(&big_str));
}
