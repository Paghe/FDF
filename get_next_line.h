/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:05:16 by apaghera          #+#    #+#             */
/*   Updated: 2023/01/03 18:00:13 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*next_line(char *stash);
size_t	ft_strl(char *s);
char	*ft_strdupgn(char *s);
char	*ft_strjoingn(char *s, char *s2);
char	*ft_strchrgn(char *s, int c);
char	*ft_new_line(char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*get_read_line(int fd, char *stash);
#endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif