/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:41:42 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/23 15:54:11 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if (!str || !len)
		return (NULL);
	count = -1;
	array = (char *)malloc((len + 1) * sizeof(char));
	while (++count < len)
		array[count] = str[count];
	array[count] = '\0';
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len = len + ft_strlen(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	free(s1);
	return (array);
}

int	check_retour(char	*big_str)
{
	int		i;

	if (!big_str)
		return (0);
	i = -1;
	while (big_str[++i])
		if (big_str[i] == 10)
			return (1);
	return (0);
}

char	*aff_ligne(char **big_str)
{
	int		i;
	char	*return_line;
	char	*str;

	if (!*big_str)
		return (NULL);
	str = *big_str;
	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return_line = ft_strdup(str, i);
	*big_str = ft_strdup(str + i, ft_strlen(str + i));
	if (str)
		free(str);
	str = NULL;
	return (return_line);
}
