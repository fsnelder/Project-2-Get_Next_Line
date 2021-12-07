/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:31:45 by fsnelder      #+#    #+#                 */
/*   Updated: 2021/11/23 14:34:31 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

static int	find_new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	*check_for_newline(char *str_newline, char *s)
{
	int	i;

	i = ft_check_end(s);
	ft_memmove(&s[0], &s[i], BUFFER_SIZE - i);
	ft_bzero(&s[BUFFER_SIZE - i], i);
	return (str_newline);
}

static int	check_for_previous_buffer(char **str_newline, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[0] == '\n')
	{
		ft_memmove(*str_newline, &s[0], 1);
		ft_memmove(&s[0], &s[1], i);
		ft_bzero(&s[i], 1);
		return (1);
	}
	if (find_new_line(s) == 1 && *str_newline[0] != '\n')
	{
		ft_memmove(*str_newline, s, ft_check_end(s));
		*str_newline = check_for_newline(*str_newline, s);
		return (1);
	}
	else if (s[0] != '\0' && *str_newline[0] != '\n')
	{
		*str_newline = ft_join_last_data(*str_newline, s);
		if (!str_newline)
			return (0);
	}
	return (0);
}

static char	*check_read_return(char *str_newline, char *s, int read_return)
{
	if (read_return == -1 || (read_return == 0 && s[0] == '\0'))
	{
		free (str_newline);
		return (NULL);
	}
	if (read_return == 0)
	{
		ft_bzero (s, ft_check_end(s));
		return (str_newline);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		s[OPEN_MAX][BUFFER_SIZE + 1];
	char			*str_newline;
	int				read_return;

	if (BUFFER_SIZE == 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	str_newline = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!str_newline)
		return (NULL);
	if (s[fd][0] != '\0' && check_for_previous_buffer(&str_newline, s[fd]))
		return (str_newline);
	while (find_new_line(str_newline) == 0)
	{
		read_return = read (fd, s[fd], BUFFER_SIZE);
		if (read_return == 0 || read_return == -1)
			return (check_read_return(str_newline, s[fd], read_return));
		if (read_return < BUFFER_SIZE)
			ft_bzero(&s[fd][read_return], BUFFER_SIZE - read_return);
		str_newline = ft_join_last_data(str_newline, s[fd]);
		if (!str_newline)
			return (NULL);
		if (find_new_line(s[fd]) == 1)
			return (check_for_newline(str_newline, s[fd]));
	}
	return (str_newline);
}
