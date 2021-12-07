/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fsnelder <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:33:02 by fsnelder      #+#    #+#                 */
/*   Updated: 2021/11/23 13:33:03 by fsnelder      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	int				j;
	unsigned char	*str;

	i = 0;
	j = 0;
	str = malloc(size * count);
	if (str == 0)
		return (NULL);
	size = size * count;
	while (size > 0)
	{
		str[j] = i;
		size--;
		j++;
	}
	return (str);
}

void	*ft_memmove(char *dst, char *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst <= src)
	{
		while (len > 0 && i < len)
		{
			((unsigned char *) dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

size_t	ft_check_end(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		 if (str[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = s;
	while (n > 0)
	{	
		*str++ = i;
		n--;
	}
}

char	*ft_join_last_data(char *str_newline, char *s_buff)
{
	int		s_len;
	int		str_len;
	char	*join_str;

	s_len = ft_check_end(s_buff);
	str_len = ft_check_end(str_newline);
	join_str = ft_calloc(str_len + s_len + 1, sizeof(char));
	if (!join_str)
	{
		free (str_newline);
		return (NULL);
	}
	ft_memmove(join_str, str_newline, str_len);
	ft_memmove(&join_str[str_len], s_buff, s_len);
	free (str_newline);
	return (join_str);
}
