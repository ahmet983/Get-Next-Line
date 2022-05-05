/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomak <acomak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:00:38 by acomak            #+#    #+#             */
/*   Updated: 2022/03/15 11:58:08 by acomak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*dizi_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	dizi_str[fd] = ft_read_to_left_str(fd, dizi_str[fd]);
	if (!dizi_str[fd])
	{
		return (0);
	}
	line = ft_get_line(dizi_str[fd]);
	dizi_str[fd] = ft_new_left_str(dizi_str[fd]);
	return (line);
}
