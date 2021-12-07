/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:34:09 by fsnelder      #+#    #+#                 */
/*   Updated: 2021/11/23 13:34:14 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(char *ptr, size_t size, size_t quant);
void		*ft_memmove(char *dst, char *src, size_t len);
size_t		ft_check_end(char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_join_last_data(char *str_newline, char *s_buff);
char		*get_next_line(int fd);

#endif
