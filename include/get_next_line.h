/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-pae <bryan.vanpaemel@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:48:07 by bvan-pae          #+#    #+#             */
/*   Updated: 2023/11/21 15:00:05 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*gnl_join(char *s1, char *s2);
char	*gnl_chr(char *s, int c);
char	*gnl_calloc(size_t size);
char	*gnl_get(int fd, char *left);
char	*gnl_line(char *left);
char	*gnl_mod(char *left);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
