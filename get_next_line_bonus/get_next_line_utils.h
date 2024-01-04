/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:27:07 by ejohnson          #+#    #+#             */
/*   Updated: 2023/11/18 23:54:12 by ejohnson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

void *malloc_and_init(size_t size);
void memzero(char *buff, size_t size);
size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
void	*ft_memcpy(void *dest, const void *src, size_t leng);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);

#endif
