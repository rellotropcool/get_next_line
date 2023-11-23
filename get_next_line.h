/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:41:51 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/23 15:53:57 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *s1, char *s2);
int		check_retour(char	*big_str);
char	*aff_ligne(char **big_str);
char	*get_next_line(int fd);

#endif
