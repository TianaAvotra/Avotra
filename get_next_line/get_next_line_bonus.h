/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:03:14 by hrasolom          #+#    #+#             */
/*   Updated: 2024/04/15 08:05:24 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_join_free(char	*text, char	*buffer);
char	*read_first_line(int fd, char *text);
char	*get_line(char *text);
char	*clean_first_line(char *text);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char	*s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, unsigned int n);
void	*ft_calloc(unsigned int count, unsigned int size);

#endif
