/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:00:00 by jagan             #+#    #+#             */
/*   Updated: 2026/04/30 11:45:34 by jagan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static char	*make_line(char *buf, ssize_t start, ssize_t end)
{
	char	*line;
	ssize_t	len;

	len = end - start;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, buf + start, (int)len);
	line[len] = '\0';
	return (line);
}

char	*read_line(void)
{
	static char		buf[4096];
	static ssize_t	s = 0;
	static ssize_t	e = 0;
	ssize_t			i;
	ssize_t			start;

	if (s >= e)
	{
		e = read(STDIN_FILENO, buf, sizeof(buf));
		s = 0;
		if (e <= 0)
			return (NULL);
	}
	start = s;
	i = s;
	while (i < e && buf[i] != '\n')
		i++;
	s = i;
	if (s < e && buf[s] == '\n')
		s++;
	return (make_line(buf, start, i));
}
