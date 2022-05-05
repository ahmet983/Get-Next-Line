/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomak <acomak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:37:04 by acomak            #+#    #+#             */
/*   Updated: 2022/03/15 11:55:06 by acomak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_dizi_str(int fd, char *dizi_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		return (0);
	}
	rd_bytes = 1;
	while (!ft_strchr(dizi_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_bytes] = '\0';
		dizi_str = ft_strjoin(dizi_str, buff);
	}
	free(buff);
	return (dizi_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*dizi_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	dizi_str = ft_read_to_dizi_str(fd, dizi_str);
	if (!dizi_str)
	{
		return (0);
	}
	line = ft_get_line(dizi_str);
	dizi_str = ft_new_left_str(dizi_str);
	return (line);
}

/* int main()
{
	int fd;
	fd = open("fff", 0);
	get_next_line(fd);
	printf("%s", get_next_line(fd));
} */
